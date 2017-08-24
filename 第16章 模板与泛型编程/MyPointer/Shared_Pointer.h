#pragma once

#include <iostream>
#include <functional>
#include "Delete.h"
using namespace std;

template<typename T>
class Shared_Pointer;
template<typename T>
void swap(Shared_Pointer<T> &lhs, Shared_Pointer<T> &rhs){
	using std::swap;
	swap(lhs.data, rhs.data);
	swap(lhs.ref_count, rhs.ref_count);
	swap(lhs.deleter, rhs.delter);
}

template<typename T>
class Shared_Pointer{
public:
	using size_type = unsigned int;
	Shared_Pointer():data(nullptr), ref_count(new size_type(1)), deleter(Delete()){}
	Shared_Pointer(T *ptr, function<void(T*)> d = Delete()):data(ptr), ref_count(new size_type(1)), deleter(d){}//Ĭ�ϲ���ΪDelete()
	
	//�������Ƴ�Ա��
	//��������
	Shared_Pointer(const Shared_Pointer<T> &rhs):data(rhs.data), ref_count(new size_type(*rhs.ref_count+1)), deleter(rhs.deleter){}
	//������ֵ����
	Shared_Pointer<T>& operator=(const Shared_Pointer<T> &rhs){
		//�������Ҳ��������
		++*rhs.ref_count;//��ֹ �Ը�ֵbug
		decrement_and_delete();//�ݼ������󣨱���ֵ�������ü������������
		data = rhs.data;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		return *this;
	}
	//�ƶ�����
	Shared_Pointer(Shared_Pointer<T> &&rhs)noexcept : data(rhs.data), ref_count(rhs.ref_count), deleter(move(rhs.deleter)){
		rhs.data = rhs.ref_count = nullptr;
	} 
	Shared_Pointer& operator=(Shared_Pointer<T> &&rhs)noexcept {
		//�൱�ڰ�ԭ���Ŀռ�ת�Ƶ�����ռ��ϣ���ô�Ͳ����� ���ü����ı仯
		data = rhs.data;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		rhs.data = rhs.ref_count = nullptr;
		rhs.deleter = function<void(T*)>(); 
	}
	//��������
	~Shared_Pointer(){
		decrement_and_delete();//
	} 
	
	//����ת��
	operator bool() const{
		return data ? true : false; 
	}
	//������
	T& operator*() const{
		return *data;
	} 
	//��ͷ����
	T* operator->() const{
		return &*data;
	} 
	
	//���ʼ���
	size_type use_count() const{
		return *ref_count;
	}
	//��õײ�ָ��
	T* get() const{
		return data;
	} 
	//���Ƿ�ֻ��һ�����ö���
	bool unique() const{
		return 1 == use_count();
	} 
	//����
	void swap(Shared_Pointer<T> &rhs){
		::swap(*this, rhs);//�������swap 
	} 
	
	//reset:free the object point to, if unique
	void reset(){
		decrement_and_delete();
	} 
	//reset with new raw pointer
	void reset(T *ptr){
		if (ptr != data) {
			decrement_and_delete();
			data = ptr;
			ref_count = new size_type(1);//�������� 
		}
	}
	//reset with new raw pointer and deleter
	void reset(T *ptr, function<void(T*)> &del){
		reset(ptr);
		deleter = del;
	}
	
	
private:
	void decrement_and_delete(){
		if (data && 0 == --*ref_count){
			delete ref_count;
			deleter(data);//���û���κζ���������ָ���У��򽫶���ͼ����������� 
		}
		else if (data){
			delete ref_count;
		}
		data = ref_count = nullptr;
	}
	
	T* data = nullptr;//������ݵ�ָ��
	size_type *ref_count = nullptr; //����������һ������������Ŀ�������һ��ָ�� 
	function<void(T*)> deleter;
};

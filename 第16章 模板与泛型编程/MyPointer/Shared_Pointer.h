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
	Shared_Pointer(T *ptr, function<void(T*)> d = Delete()):data(ptr), ref_count(new size_type(1)), deleter(d){}//默认参数为Delete()
	
	//拷贝控制成员：
	//拷贝构造
	Shared_Pointer(const Shared_Pointer<T> &rhs):data(rhs.data), ref_count(new size_type(*rhs.ref_count+1)), deleter(rhs.deleter){}
	//拷贝赋值函数
	Shared_Pointer<T>& operator=(const Shared_Pointer<T> &rhs){
		//先自增右侧运算对象
		++*rhs.ref_count;//防止 自赋值bug
		decrement_and_delete();//递减左侧对象（被赋值对象）引用计数，检查销毁
		data = rhs.data;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		return *this;
	}
	//移动操作
	Shared_Pointer(Shared_Pointer<T> &&rhs)noexcept : data(rhs.data), ref_count(rhs.ref_count), deleter(move(rhs.deleter)){
		rhs.data = rhs.ref_count = nullptr;
	} 
	Shared_Pointer& operator=(Shared_Pointer<T> &&rhs)noexcept {
		//相当于把原来的空间转移到这个空间上，那么就不存在 引用计数的变化
		data = rhs.data;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		rhs.data = rhs.ref_count = nullptr;
		rhs.deleter = function<void(T*)>(); 
	}
	//析构函数
	~Shared_Pointer(){
		decrement_and_delete();//
	} 
	
	//类型转换
	operator bool() const{
		return data ? true : false; 
	}
	//解引用
	T& operator*() const{
		return *data;
	} 
	//箭头访问
	T* operator->() const{
		return &*data;
	} 
	
	//访问计数
	size_type use_count() const{
		return *ref_count;
	}
	//获得底层指针
	T* get() const{
		return data;
	} 
	//看是否只有一个引用对象
	bool unique() const{
		return 1 == use_count();
	} 
	//交换
	void swap(Shared_Pointer<T> &rhs){
		::swap(*this, rhs);//调用外层swap 
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
			ref_count = new size_type(1);//重新设置 
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
			deleter(data);//如果没有任何对象存在这个指针中，则将对象和计数器都销毁 
		}
		else if (data){
			delete ref_count;
		}
		data = ref_count = nullptr;
	}
	
	T* data = nullptr;//存放数据的指针
	size_type *ref_count = nullptr; //用来计数，一个对象本身和它的拷贝共用一个指针 
	function<void(T*)> deleter;
};

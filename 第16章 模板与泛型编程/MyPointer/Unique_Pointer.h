#pragma once
#include "Delete.h"

template<typename, typename> class Unique_Pointer;
template<typename T, typename D> 
void swap(Unique_Pointer<T, D>& lhs, Unique_Pointer<T, D>& rhs);

template<typename T, typename D = Delete>
class Unique_Pointer{
	friend void swap<T,D>(Unique_Pointer<T, D>& lhs, Unique_Pointer<T, D>& rhs);
public:
	//unique���ܿ��������Թ��ڿ�����������Ϊdelete 
	Unique_Pointer(const Unique_Pointer &) = delete;
	Unique_Pointer& operator=(const Unique_Pointer &) = delete;
	
	Unique_Pointer() = default;
	explicit Unique_Pointer(T *ptr, D del = D()): data(ptr), deleter(del){}
	
	//move constructor
	Unique_Pointer(Unique_Pointer &&rhs)noexcept:data(rhs.data){
		rhs.data = nullptr;
	}
	//move assignment
	Unique_Pointer& operator=(Unique_Pointer &&rhs)noexcept;
	
	//member function
	T& operator*() const{
		return *data;
	}
	T* operator->() const{
		return &*data;
	}
	operator bool() const{
		return data ? true : false;
	}
	//get underlying pointer;
	T* get() const{
		return data;
	}
	//swap member function
	void swap(Unique_Pointer<T,D> &rhs){
		::swap(*this, rhs);
	}
	
	//free and make it point to nullptr or p's ponter
	void reset(){
		deleter(data);
		data = nullptr;
	}
	void reset(T *ptr){
		deleter(data);
		data = ptr;
	}
	
	//return ptr and make data to nullptr
	T* release();
	
	~Unique_Pointer(){
		deleter(data);
	}
private:
	T *data;//Ϊʲôû�м���Ԫ������Ҳ���Է��ʣ�����������###### 
	D deleter;//= D();//D()��Ӧ�÷��������ʼ����Ӧ�÷ŵ������##�����ڹ�������ʱ��ͳ�ʼ���ˡ�Ĭ����Delete 
};

template<typename T, typename D> 
void swap(Unique_Pointer<T, D>& lhs, Unique_Pointer<T, D>& rhs){
	using std::swap;
	swap(lhs.data, rhs.data);
	swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D>//�����ʱ����Բ���дĬ��
Unique_Pointer<T,D>& Unique_Pointer<T,D>::operator=(Unique_Pointer &&rhs)noexcept{
	//prevent self-assignment
	if (data != rhs.data){
		deleter(data);
		data = nullptr;
		::swap(*this, rhs);
	}
	return *this;
}

template<typename T, typename D>
T* Unique_Pointer<T, D>::release(){
	auto ret = data;
	data = nullptr;
	return ret;
} 

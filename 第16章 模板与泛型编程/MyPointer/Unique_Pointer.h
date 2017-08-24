#pragma once
#include "Delete.h"

template<typename, typename> class Unique_Pointer;
template<typename T, typename D> 
void swap(Unique_Pointer<T, D>& lhs, Unique_Pointer<T, D>& rhs);

template<typename T, typename D = Delete>
class Unique_Pointer{
	friend void swap<T,D>(Unique_Pointer<T, D>& lhs, Unique_Pointer<T, D>& rhs);
public:
	//unique不能拷贝，所以关于拷贝都被声明为delete 
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
	T *data;//为什么没有加友元函数，也可以访问？？？？？？###### 
	D deleter;//= D();//D()不应该放在这里初始化，应该放到构造里。##必须在构造对象的时候就初始化了。默认是Delete 
};

template<typename T, typename D> 
void swap(Unique_Pointer<T, D>& lhs, Unique_Pointer<T, D>& rhs){
	using std::swap;
	swap(lhs.data, rhs.data);
	swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D>//定义的时候可以不用写默认
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

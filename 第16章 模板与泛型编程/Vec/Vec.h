#pragma once

#include <iostream>
#include <initializer_list>
#include <memory>
#include <utility>//pair在其中，翻译为：多用途的头文件
 
using namespace std;

template<typename T>
class Vec{
public:
	typedef size_t size_type;//定义自己的size_type 
	//构造函数 
	Vec():curr(nullptr), first_free(nullptr), cap(nullptr){}
	Vec(initializer_list<T> il);//需要在函数体内构造 
	//拷贝控制函数
	Vec(const Vec &);//拷贝构造函数
	Vec& operator=(const Vec &);//拷贝赋值函数
	~Vec();//析构函数 
	//移动控制函数
	Vec(Vec &&) noexcept;
	Vec& operator=(Vec &&)noexcept;

	//普通成员函数	
	bool empty() const{
		//常量对象只能调用常量成员函数
		return size() == 0; 
	}
	const size_type size() const{
		return first_free - curr;
	}
	const size_type capacity() const{
		return cap - curr;
	}
	T* begin(){
		return curr;
	}
	T* end(){
		return first_free;
	}
	const T* cbegin() const{
		return curr;
	}
	const T* cend() const{
		return first_free;
	}
	
	//插入、删除操作
	void push_back(const T &);
	T pop_back(); 
	
	template<typename...Args>
	void emplace_back(Args&&...args)//扩展模板参数包，模式是&&，每个参数都是右值引用
	{
		chk_n_alloc();//先检查是否有多余空间
		//构造
		alloc.construct(first_free++, forward<Args>(args)...);//既扩展了模板参数包，又扩展了函数参数包。对每个参数就要这样调用 
	} 
	
	//访问元素操作
	T& operator[](size_type i); 
	
private://私有的工具类，不开放给外界用
	static allocator<T> alloc;//分配内存的静态变量,公用 
	//由于有很多成员函数有相同的操作：拷贝，赋值，销毁。而在拷贝和赋值之前，都要进行相应的检查，所以把这些检查细节都抽出来。
	
	//分配内存，并拷贝一个给定范围的元素,返回的是一个返回pair 
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	
	//检查是否有空间容纳一个新元素的空间，如果没有空间，则调用reallocate来分配内存
	void chk_n_alloc(){
		if (size() == capacity()){
			reallocate();
		}
	} 
	
	//获得更多内存并拷贝或者移动到新的空间，以便可以push更多元素 
	void reallocate();
	
	//销毁元素，并释放内存 
	void free();
private:
	//首元素指针，有效元素尾指针，分配空间尾指针
	T *curr;
	T *first_free;
	T *cap;
};
//定义静态的allocator 
template<typename T>
allocator<T> Vec<T>::alloc;

//工具函数首先定义：
template<typename T> 
pair<T*, T*> Vec<T>::alloc_n_copy(const T* first, const T* last){
	//先用allocate分配，在用construct构造
	auto data = alloc.allocate(last - first);
	return {data, uninitialized_copy(first, last, data)};//隐式地构造了pair. uninitialized_copy()返回构造后的尾指针 
}

//重新分配空间，策略是：在原来的空间大小上分配两倍，如果原来空间为0，则分配1 
template<typename T>
void Vec<T>::reallocate(){
	auto newSize = size()?2*size():1;
	auto newData = alloc.allocate(newSize);
	
	//把curr和first_free 的元素一个一个拷贝/移动到新的空间里
	auto dst = newData;//要保存data，传给curr...dst means destination
	for (size_type i = 0; i != size(); ++i){
		alloc.construct(dst++, move(*curr++));//move curr的内容，因为curr只需要一个用户 
	} 
	curr = newData;
	first_free = dst;//dst移动完后到尾后了。 
	cap = newData + newSize;
}

template<typename T> 
void Vec<T>::free(){
	//销毁成员，释放内存
	if (curr){
		for (auto p = first_free; p != curr;){
			alloc.destroy(--p);
		}
		alloc.deallocate(curr, cap - curr);//reallocate的指针不能为空，并且第二个空间必须和申请时候的大小是一样的。 
	}
	//也可以用for_each和lambda表达式来做销毁，for_each是解引用的，所以要取地址 
}

//外部定义的构造函数 
template<typename T>
Vec<T>::Vec(initializer_list<T> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	curr = data.first;
	first_free = cap = data.second;
}

//成员函数：
//拷贝控制函数
template<typename T> 
Vec<T>::Vec(const Vec &rhs){
	cout << "copy construction"<<endl;
	 auto data = alloc_n_copy(rhs.curr, rhs.first_free);
	 curr = data.first;
	 first_free = cap = data.second;
}
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs){//参数Vec已经在作用域内了
	//先申请内存，拷贝元素，保存原来的
	cout << "copy assignment"<<endl; 
	auto data = alloc_n_copy(rhs.curr, rhs.first_free);
	free();//释放原来的内存
	curr = data.first;
	first_free = cap = data.second;
	return *this;
}
template<typename T>
Vec<T>::~Vec(){
	free(); 
}

//移动控制 
template<typename T>
Vec<T>::Vec(Vec &&rhs)noexcept
	:curr(rhs.curr), first_free(rhs.first_free), cap(rhs.cap)
{
	cout << "move construction"<<endl;
	rhs.curr = rhs.first_free = rhs.cap = nullptr;
}
template<typename T>
Vec<T>& Vec<T>::operator=(Vec &&r)noexcept{
	//检查是否是自赋值
	cout << "move assignment"<<endl;
	if (this != &r){
		curr = r.curr;
		first_free = r.first_free;
		cap = r.cap;
		r.curr = r.first_free = r.cap = nullptr;
	} 
	return *this;
}

//插入、删除操作 
template<typename T>
void Vec<T>::push_back(const T &value){
	chk_n_alloc();//先检查空间
	alloc.construct(first_free, value);//用value来构造first_free位置的元素
	first_free++; 
}
template<typename T>
T Vec<T>::pop_back(){
	//如果能pop，则容器一定不能为空，把这个考虑的事情交给用户就可以了
	--first_free;
	auto ret = *first_free;
	alloc.destroy(first_free);
	return ret; 
}

//访问操作
template<typename T>
T& Vec<T>::operator[](size_type i){
	return *(curr + i);
} 








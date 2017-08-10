#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <initializer_list>
using namespace std;

class StrVec{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(initializer_list<string> il);
	//拷贝构造函数
	StrVec(const StrVec&);
	//拷贝赋值函数
	StrVec& operator=(const StrVec&);
	//析构函数	
	~StrVec(); 

	//移动构造函数
	StrVec(StrVec &&s) noexcept
		:elements(s.elements),first_free(s.first_free),cap(s.cap){
		s.elements = s.first_free = s.cap = nullptr;
		//令s进入这样的状态---对其运行析构函数是安全的	
	} 

	//成员函数
	void push_back(const string&);
	size_t size() const{
		return first_free - elements;
	}
	size_t capacity() const{
		return cap - elements;
	}
	string *begin() const{
		return elements;
	}
	string *end()const{
		return first_free;
	}
	void reserve(size_t newCap);
	void alloc_to_move(size_t newCap);
	void resize(size_t newCap, const string &str = "");
	
private:
	//内部工具函数
	pair<string*, string*> alloc_n_copy(const string *beg, const string *end); 
	void chk_n_alloc(){
		if (size()==capacity()){
			reallocate();//重新分配内存 
		}
		//否则继续 
	}
	void free();//销毁元素并释放内存
	void reallocate();//获得更多内存并拷贝已有元素
	
private:
	static allocator<string> alloc;//分配元素 
	
	string *elements;//指向数组的首元素
	string *first_free;//指向数组的第一个空闲元素
	string *cap;//指向数组尾后位置的指针 
};

#endif

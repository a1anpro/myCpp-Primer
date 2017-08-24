#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>
using namespace std;

template<typename T>
class Blob{
public:
	//类型定义放在前面 
	typedef T value_type;//将value_type代替T类型
	typedef typename vector<T>::size_type size_type;//为什么之前要有typename
	
	//构造函数
	Blob();
	Blob(initializer_list<T> il);
	template<typename It>
	Blob(It b, It e);

	//Blob中的元素数目
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	//添加和删除元素：
	void push_back(const T &t) const{data->push_back(t);}
	//移动版本：
	void push_back(T &&t) noexcept{data->push_back(move(t));}
	void pop_back(); 
	
	T& back();
	T& front(); 
	T& back() const;//back的重载版本
	T& front() const;//front的重载版本 
	T& operator[](size_type i);
	T& operator[](size_type i) const;
	
private:
	shared_ptr<vector<T>> data;	
	void check(size_type i, const string &msg) const;//检查函数 
};

//构造函数 
template<typename T>
Blob<T>::Blob():data(make_shared<vector<T>>()){
}
template<typename T>//因为每个实例都要生成特定类型的类，所以定义要带上模版参数列表 
Blob<T>::Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)){
}
template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e):data(make_shared<vector<T>>(b,e)){//可以用make_shared的范围来构造 
	cout << "模板成员构造函数"<<endl;
}


//检查下标是否合法 
template<typename T>
void Blob<T>::check(size_type i, const string &msg) const{
	if (i >= data->size()){
		throw out_of_range(msg);
	}
}
//弹出尾元素 
template<typename T>
void Blob<T>::pop_back(){
	check(0, "pop on empty Blob");
	return data->pop_back();
}

//访问函数 
template<typename T>
T& Blob<T>::back(){
	check(0, "back on empty Blob");
	return data->back();
}
template<typename T>
T& Blob<T>::front(){
	check(0, "front on empty Blob");
	return data->front();
}
template<typename T>
T& Blob<T>::operator[](size_type i){
	check(0, "subscript out of range");
	return (*data)[i];
}
//重载的访问函数，常量对象版本s 
template<typename T>
T& Blob<T>::back() const{
	check(0, "back on empty Blob");
	return data->back();
}
template<typename T>
T& Blob<T>::front() const{
	check(0, "front on empty Blob");
	return data->front();
}
template<typename T>
T& Blob<T>::operator[](size_type i) const{
	check(0, "subscript out of range");
	return (*data)[i];
}






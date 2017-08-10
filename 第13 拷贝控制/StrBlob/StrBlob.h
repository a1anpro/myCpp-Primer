#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class StrBlob{
public:
	using size_type = vector<string>::size_type;
	StrBlob():data(make_shared<vector<string>>()){}
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}
	//拷贝构造函数.il的拷贝是共享底层元素 
//	StrBlob(const StrBlob &rhs){
//		data = make_shared<vector<string>>();//
//		for (auto i:*rhs.data){
//			data->push_back(i);//把元素一个个放入 
//		}
//	}
//	StrBlob& operator=(const StrBlob&);
	
	//标准拷贝构造函数，不需要一个个操作.因为make_shared<vector<string>>()的参数可以拷贝。就是说
	//可以给它传一个vector<string>的参数，他会自己调用相应的拷贝 
	StrBlob(const StrBlob &rhs):data(make_shared<vector<string>>(*rhs.data)){} 
	StrBlob& operator=(const StrBlob &rhs);
private:
	shared_ptr<vector<string>> data;
};

StrBlob& StrBlob::operator=(const StrBlob &rhs){
	data = make_shared<vector<string>>(*rhs.data);
	return *this;//智能指针会自己释放内存 
}

//StrBlob& StrBlob::operator=(const StrBlob &rhs){
//	vector<string> *new_ptr = new vector<string>;
//	for (auto i:*rhs.data) new_ptr->push_back(i);
//	data.reset(new_ptr);//释放原来的空间,并且指向新的空间。 
//	return *this; 
//}

#endif

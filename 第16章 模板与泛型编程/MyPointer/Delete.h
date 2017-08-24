#pragma once
#include <iostream>
using namespace std;

struct Delete{
	//删除器：默认使用的，我们把它抽象出来给大家共用 
	template<typename T>
	void operator()(T *ptr) const{
		cout << "default deleter"<<endl;
		delete ptr;
	}
};

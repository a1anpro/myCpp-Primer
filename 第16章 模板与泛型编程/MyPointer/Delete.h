#pragma once
#include <iostream>
using namespace std;

struct Delete{
	//ɾ������Ĭ��ʹ�õģ����ǰ��������������ҹ��� 
	template<typename T>
	void operator()(T *ptr) const{
		cout << "default deleter"<<endl;
		delete ptr;
	}
};

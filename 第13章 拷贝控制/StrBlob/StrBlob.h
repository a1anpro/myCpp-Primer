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
	//�������캯��.il�Ŀ����ǹ���ײ�Ԫ�� 
//	StrBlob(const StrBlob &rhs){
//		data = make_shared<vector<string>>();//
//		for (auto i:*rhs.data){
//			data->push_back(i);//��Ԫ��һ�������� 
//		}
//	}
//	StrBlob& operator=(const StrBlob&);
	
	//��׼�������캯��������Ҫһ��������.��Ϊmake_shared<vector<string>>()�Ĳ������Կ���������˵
	//���Ը�����һ��vector<string>�Ĳ����������Լ�������Ӧ�Ŀ��� 
	StrBlob(const StrBlob &rhs):data(make_shared<vector<string>>(*rhs.data)){} 
	StrBlob& operator=(const StrBlob &rhs);
private:
	shared_ptr<vector<string>> data;
};

StrBlob& StrBlob::operator=(const StrBlob &rhs){
	data = make_shared<vector<string>>(*rhs.data);
	return *this;//����ָ����Լ��ͷ��ڴ� 
}

//StrBlob& StrBlob::operator=(const StrBlob &rhs){
//	vector<string> *new_ptr = new vector<string>;
//	for (auto i:*rhs.data) new_ptr->push_back(i);
//	data.reset(new_ptr);//�ͷ�ԭ���Ŀռ�,����ָ���µĿռ䡣 
//	return *this; 
//}

#endif

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
	//�������캯��
	StrVec(const StrVec&);
	//������ֵ����
	StrVec& operator=(const StrVec&);
	//��������	
	~StrVec(); 

	//�ƶ����캯��
	StrVec(StrVec &&s) noexcept
		:elements(s.elements),first_free(s.first_free),cap(s.cap){
		s.elements = s.first_free = s.cap = nullptr;
		//��s����������״̬---�����������������ǰ�ȫ��	
	} 

	//��Ա����
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
	//�ڲ����ߺ���
	pair<string*, string*> alloc_n_copy(const string *beg, const string *end); 
	void chk_n_alloc(){
		if (size()==capacity()){
			reallocate();//���·����ڴ� 
		}
		//������� 
	}
	void free();//����Ԫ�ز��ͷ��ڴ�
	void reallocate();//��ø����ڴ沢��������Ԫ��
	
private:
	static allocator<string> alloc;//����Ԫ�� 
	
	string *elements;//ָ���������Ԫ��
	string *first_free;//ָ������ĵ�һ������Ԫ��
	string *cap;//ָ������β��λ�õ�ָ�� 
};

#endif

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>
using namespace std;

template<typename T>
class Blob{
public:
	//���Ͷ������ǰ�� 
	typedef T value_type;//��value_type����T����
	typedef typename vector<T>::size_type size_type;//Ϊʲô֮ǰҪ��typename
	
	//���캯��
	Blob();
	Blob(initializer_list<T> il);
	template<typename It>
	Blob(It b, It e);

	//Blob�е�Ԫ����Ŀ
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	//��Ӻ�ɾ��Ԫ�أ�
	void push_back(const T &t) const{data->push_back(t);}
	//�ƶ��汾��
	void push_back(T &&t) noexcept{data->push_back(move(t));}
	void pop_back(); 
	
	T& back();
	T& front(); 
	T& back() const;//back�����ذ汾
	T& front() const;//front�����ذ汾 
	T& operator[](size_type i);
	T& operator[](size_type i) const;
	
private:
	shared_ptr<vector<T>> data;	
	void check(size_type i, const string &msg) const;//��麯�� 
};

//���캯�� 
template<typename T>
Blob<T>::Blob():data(make_shared<vector<T>>()){
}
template<typename T>//��Ϊÿ��ʵ����Ҫ�����ض����͵��࣬���Զ���Ҫ����ģ������б� 
Blob<T>::Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)){
}
template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e):data(make_shared<vector<T>>(b,e)){//������make_shared�ķ�Χ������ 
	cout << "ģ���Ա���캯��"<<endl;
}


//����±��Ƿ�Ϸ� 
template<typename T>
void Blob<T>::check(size_type i, const string &msg) const{
	if (i >= data->size()){
		throw out_of_range(msg);
	}
}
//����βԪ�� 
template<typename T>
void Blob<T>::pop_back(){
	check(0, "pop on empty Blob");
	return data->pop_back();
}

//���ʺ��� 
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
//���صķ��ʺ�������������汾s 
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






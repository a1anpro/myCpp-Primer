#include "Blob.h"
#include <exception>

template<typename T>class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T>
class BlobPtr{//û�и������һ������const Blob�Ĺ��캯�������Բ��ܽ��ܳ������� 
	/*
	General friendship that each instantiation of BlobPtr grants access to
	 the version of the equality and relational operators instantiated with the same type.
	 ͨ���Ѻù�ϵ��BlobPtr��ÿ��ʵ������ͬʵ������operator==����Ϊ��Ԫ����(����T��ͬ��) 
	*/
	friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
public:
	typedef T value_type;
	typedef typename Blob<T>::size_type size_type;//������typename��Ϊ��˵���������õ�Blob<T>::size_type��һ�����Ͷ�����һ������ 
//	using Blob<T>::size_type size_type;//ֱ��ʹ��Blob��size_type 
	
	BlobPtr();
	BlobPtr(Blob<T> &b, size_type c = 0);//Ӧ��Ҫ��һ��Ĭ�ϲ��� 
		
	//���weakָ��汾Ӧ�����Դ����±�ȥ����Ԫ�أ��������������
	//operator*()����,���ʵ���currλ�õ�Ԫ��
	T& operator*(); 
	
	//�����Լ������
	BlobPtr& operator++();//���ص����Լ�
	BlobPtr& operator--(); 
	//���������Լ�
	BlobPtr operator++(int);
	BlobPtr operator--(int); 
	
private:
	shared_ptr<vector<T>> check(size_type i, const string &msg);
	weak_ptr<vector<T>> ptr;
	size_type curr;//��ǰ��λ�� 
};

template<typename T>
BlobPtr<T>::BlobPtr():ptr(make_shared<vector<T>>()),curr(0){}//Ĭ�ϵģ�����Ϊ��
template<typename T>
BlobPtr<T>::BlobPtr(Blob<T> &b, size_type c):ptr(b.data), curr(c){}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_type i, const string &msg){//��Ϊ�����õ���weak_ptr������Ҫ���ָ��Ķ���ָ���Ƿ���Ч���� 
	auto ret = ptr.lock();//���ָ���shared_ptr�����Ѿ����ͷţ��򷵻�һ���ո��shared_ptr 
	if (!ret){
		throw runtime_error("unbound BlobPtr");
	}
	if (i >= ptr->size()){//�ɹ��� 
		throw out_of_range(msg);
	}
	return ret;
}
//����Ԫ�أ�
template<typename T>
T& BlobPtr<T>::operator*(){//���ϵİ汾��const�ģ�����Ԫ��ΪʲôҪ��const������ 
	auto data = check(curr, "visit a non-exist position");
	//���������ľͱ��ݵ��������ˣ�Ӧ��Ҫ�и�����Ŀǰ�����ᡣ
	return (*data)[curr]; 
}

//�����Լ������
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()//���ص����Լ�
{
	check(curr, "curr already out_of_range(++)");
	//if not out:
	++curr;
	return *this;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
	--curr;//���curr�Ѿ���0�ˣ���--֮����һ���ܴ����
	check(curr, "decrement pass begin of BlobPtr");
	return *this; 
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)//���ص����Լ�
{
	//����֮ǰ��
	auto ret = *this;
	check(curr, "curr already out_of_range(++)");
	++curr;
	return ret; 
}
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int){
	//����֮ǰ��
	auto ret = *this;
	--curr;
	check(curr, "decrement pass begin of BlobPtr");
	return ret; 
}


 

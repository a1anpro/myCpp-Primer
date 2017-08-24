#include "Blob.h"
#include <exception>

template<typename T>class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T>
class BlobPtr{//没有给这个类一个接受const Blob的构造函数，所以不能接受常量对象 
	/*
	General friendship that each instantiation of BlobPtr grants access to
	 the version of the equality and relational operators instantiated with the same type.
	 通用友好关系，BlobPtr的每个实例将相同实例化的operator==声明为友元函数(即：T相同的) 
	*/
	friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
public:
	typedef T value_type;
	typedef typename Blob<T>::size_type size_type;//必须用typename是为了说明我们引用的Blob<T>::size_type是一个类型而不是一个变量 
//	using Blob<T>::size_type size_type;//直接使用Blob的size_type 
	
	BlobPtr();
	BlobPtr(Blob<T> &b, size_type c = 0);//应该要有一个默认参数 
		
	//这个weak指针版本应该用自带的下标去访问元素，而不能随机访问
	//operator*()操作,访问的是curr位置的元素
	T& operator*(); 
	
	//自增自减运算符
	BlobPtr& operator++();//返回的是自己
	BlobPtr& operator--(); 
	//后置自增自减
	BlobPtr operator++(int);
	BlobPtr operator--(int); 
	
private:
	shared_ptr<vector<T>> check(size_type i, const string &msg);
	weak_ptr<vector<T>> ptr;
	size_type curr;//当前的位置 
};

template<typename T>
BlobPtr<T>::BlobPtr():ptr(make_shared<vector<T>>()),curr(0){}//默认的，构造为空
template<typename T>
BlobPtr<T>::BlobPtr(Blob<T> &b, size_type c):ptr(b.data), curr(c){}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_type i, const string &msg){//因为该类用的是weak_ptr，必须要检查指向的对象指针是否有效！！ 
	auto ret = ptr.lock();//如果指向的shared_ptr对象已经被释放，则返回一个空格的shared_ptr 
	if (!ret){
		throw runtime_error("unbound BlobPtr");
	}
	if (i >= ptr->size()){//成功绑定 
		throw out_of_range(msg);
	}
	return ret;
}
//访问元素：
template<typename T>
T& BlobPtr<T>::operator*(){//书上的版本是const的，访问元素为什么要做const操作？ 
	auto data = check(curr, "visit a non-exist position");
	//如果出问题的就被泡到这里来了，应该要有个处理，目前还不会。
	return (*data)[curr]; 
}

//自增自减运算符
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()//返回的是自己
{
	check(curr, "curr already out_of_range(++)");
	//if not out:
	++curr;
	return *this;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
	--curr;//如果curr已经是0了，则--之后会成一个很大的数
	check(curr, "decrement pass begin of BlobPtr");
	return *this; 
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)//返回的是自己
{
	//保留之前的
	auto ret = *this;
	check(curr, "curr already out_of_range(++)");
	++curr;
	return ret; 
}
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int){
	//保留之前的
	auto ret = *this;
	--curr;
	check(curr, "decrement pass begin of BlobPtr");
	return ret; 
}


 

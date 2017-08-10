#include <iostream>
using namespace std;
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlobPtr;
class StrBlob{
public:
	friend class StrBlobPtr;//以便在StrBlobPtr中构造函数的使用 
	typedef  vector<string>::size_type size_type;//重命名，将vector的类型成员设置为该类的类型成员
	StrBlob():data(make_shared<vector<string>>()){};//make_shared可以提供初始化的参数，该参数传递给T的构造函数 
	StrBlob(initializer_list<string> il):
										data(make_shared<vector<string>>(il)){};//接受一个initializer_list的对象作为构造参数.vector可以接受il 
	
	size_type size() const{return data->size();}
	bool empty() const {return data->empty();}
	
	//添加和删除元素
	void push_back(const string &t){
		data->push_back(t);
	} 
	void pop_back();
	
	//元素访问,非const版本 
	string& front();
	string& back(); 
	//const版本
	const string& front() const{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string& back() const;
	
	//定义begin()和end()，返回指向他们自己的StrBlobPtr
	StrBlobPtr begin();
	StrBlobPtr end();
	
private:
	shared_ptr<vector<string>> data;//指向vector的智能指针
	//如果data[i]不合法 抛出msg异常 
	void check(size_type i, const string &msg)const; 
};

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}

void StrBlob::check(size_type i, const string &msg)const{
	if (i>=data->size()){
		throw out_of_range(msg);//抛出异常 
	}
}
string& StrBlob::front(){
	//先要调用check来检查，如果成功的话就用底层的vector操作完成自己的工作：
	check(0, "front on empty StrBlob");
	return data->front(); 
}
string& StrBlob::back(){
	//先要调用check来检查，如果成功的话就用底层的vector操作完成自己的工作：
	check(0, "back on empty StrBlob");
	return data->back(); 
}
const string& StrBlob::back() const{//为什么只能在类内定义？ 
		check(0, "back on empty StrBlob");
		return data->back();
}
void StrBlob::pop_back(){
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

class StrBlobPtr{
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data),curr(sz){}
	
	string& deref() const;
	StrBlobPtr& incr();//前缀递增 
private:
	//如果检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<string>> check(size_t,const string&) const;
	
	//保存一个weak_ptr,意味着底层vector可能被销毁
	weak_ptr<vector<string>> wptr;
	size_t curr;//在数组中的当前位置。 
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg)const{ 
	//检查指针指向的vector是否还存在
	auto ret = wptr.lock();//w.expired()如果use_count()为0则返回true；如果expired为true，返回一个空的shared_ptr;否则返回一个指向w对象的sp
	//意思就是，如果与wptr共享数量>=1。才能得到指向wptr的shared_ptr
	if (!ret)
	{
		//如果所指对象被销毁
		throw runtime_error("unbound StrBlobPtr"); 
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);//如果所指的vector下标超界。则抛出出界 
	}
	return ret;//否则返回指向vector的shared_ptr 
}

string& StrBlobPtr::deref()const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	//前缀递增：返回递增后的对象的引用
	auto p = check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}



int main(){
	
	return 0;
}

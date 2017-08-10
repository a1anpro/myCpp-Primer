#include <iostream>
using namespace std;
#include <vector>
#include <memory>
#include <initializer_list>
class StrBlob{

public:
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
	
private:
	shared_ptr<vector<string>> data;//指向vector的智能指针
	//如果data[i]不合法 抛出msg异常 
	void check(size_type i, const string &msg)const; 
};

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



int main(){
	
	return 0;
}

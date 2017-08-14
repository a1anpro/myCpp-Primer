#include <iostream>
using namespace std;

class HasPtr{
public:
	//构造函数分配新的string 和新的计数器。将计数器置为1 
	HasPtr(const string &s = string()):
		ps(new string(s)),i(0),use(new size_t(1)){}
	//拷贝构造函数拷贝三个数据成员，并递增计数器
	HasPtr(const HasPtr &rhs):
		ps(rhs.ps),i(rhs.i),use(rhs.use){
			++*use;
		} 
	HasPtr& operator=(const HasPtr&);
	~HasPtr();	
	
private:
	string *ps;
	int i;
	size_t *use;//用来记录有多少个对象共享*ps成员 
};

HasPtr::~HasPtr(){
	//如果use递减后变为0，就释放
	if (--*use==0){
		delete use;
		delete ps;
	} 
}

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	//应该把析构和拷贝构造的工作都做了。因为递减左值的use，如果为0就要释放
	//如果拷贝赋值的是自身，那么如果先释放的话就会未定义错误。所以先递增右值
	
	++*(rhs.use);
	if (--*use==0){
		delete use;//如果没有其他用户，就释放本对象分配的成员。 
		delete ps;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

int main(){
	
	
	return 0;
}

#include <iostream>

using namespace std;

class HasPtr{
public:
	//构造函数 
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0){}
	//拷贝构造函数
	HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
	
	HasPtr& operator=(const HasPtr &hp){
		string *new_ptr = new string(*hp.ps);
		//因为ps被替换成新的了，所以要delete 
		delete ps;
		ps = new_ptr;
		i = hp.i;
		return *this;//赋值操作是将原来的覆盖。
	}	
	//析构函数
	~HasPtr(){
		delete ps;//析构函数分为两个部分：函数体 和 析构部分。函数体负责释放对象动态分配的资源，析构部分销毁非static对象 
	} 
private:
	string *ps;
	int i;
}; 
int main(){
	return 0;
}

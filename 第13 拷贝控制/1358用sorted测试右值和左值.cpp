#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo{
public:
	Foo sorted() &&;//右值this调用
	Foo sorted() const &;//左值this调用 

	vector<int> data;
};

Foo Foo::sorted() &&{
	cout << "调用右值"<<endl;
	sort(data.begin(), data.end());
	return *this;//已经有序 
}

Foo Foo::sorted() const &{
	//this是左值，不能更改
	cout << "调用左值"<<endl;
//	Foo ret(*this);//用this构造相同的
//	sort(ret.data.begin(), ret.data.end()); 
//	return ret;

	return Foo(*this).sorted();
}

int main(){
	//Foo().sorted();
	
	Foo f;
	f.sorted();
	return 0;
}

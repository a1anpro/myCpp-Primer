#include <iostream>
#include <vector>
using namespace std;

struct X{
	X(){
		cout << "X()" <<endl;
	}
	X(const X&){ 
		cout << "X(const X)" <<endl;
	}
	X& operator=(const X&){
		cout << "X& operator=(const X&)" <<endl;
		return *this;
	}
	~X(){
		cout << "~X()" <<endl;
	}
};

void f(const X& rx, X x){
	vector<X> vec;
	vec.reserve(2);//预先分配2个空间
	vec.push_back(rx);
	vec.push_back(x); 
}

int main(){
	//X x();//这是调用构造函数，而不是得到对象 
	X x;
	f(x,x);
	
	return 0;
}

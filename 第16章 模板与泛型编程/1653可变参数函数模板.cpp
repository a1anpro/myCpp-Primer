#include <iostream>
using namespace std;

template<typename T>
ostream& print(ostream &os, const T &t){//不可变参数的函数模板要提前声明，否则后面调用会无限递归 
	os << t;
	return os;//为什么ostream不能拷贝？ 
}

template<typename T, typename ... Args>
ostream& print(ostream &os, const T &t, const Args&...args){//不可变参数的函数模板要提前声明，否则后面调用会无限递归 
	os << t;
	cout << endl;
	return print(os, args...);
}

int main(){
	
	print(cout, 1, 1.2, "hello");
	
	return 0;
}

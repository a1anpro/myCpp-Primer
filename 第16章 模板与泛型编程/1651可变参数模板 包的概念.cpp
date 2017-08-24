#include <iostream>
using namespace std;

template<typename T, typename... Args>
void f(T t, const Args& ... args){
	cout << sizeof...(Args)<<endl;
	cout << sizeof...(args)<<endl;
}

int main(){
	int a = 10;
	double b = 1.2;
	string str = "hello";
	
	f(a, b, str);
	
	cout << sizeof(string("str8888889988888"))<<endl;//输出8,原来输出的是一个指针地址大小 
	
	return 0;
}

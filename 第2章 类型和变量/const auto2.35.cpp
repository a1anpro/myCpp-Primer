#include <iostream>

using  namespace std;

int main(){
	const int i = 42;
	
	auto &k = i;//k 是一个整形常量引用 
	auto h = i;
	h = 10;//事实证明h是int 
	cout << h <<endl;
	cout << k<<endl; 
	
	return 0;
} 

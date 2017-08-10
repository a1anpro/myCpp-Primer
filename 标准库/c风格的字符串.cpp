#include <iostream>
using namespace std;
#include <cstring>
int main(){
	const char str[] = "hello";
	//const char str1[5] = "hello";//容量不够，必须大于等于6； 
	
	cout << str<<endl;
	cout << sizeof(str)<<endl;
	cout << strlen(str)<<endl;//strlen是不算结束符号的 
	return 0;
} 

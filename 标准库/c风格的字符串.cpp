#include <iostream>
using namespace std;
#include <cstring>
int main(){
	const char str[] = "hello";
	//const char str1[5] = "hello";//����������������ڵ���6�� 
	
	cout << str<<endl;
	cout << sizeof(str)<<endl;
	cout << strlen(str)<<endl;//strlen�ǲ���������ŵ� 
	return 0;
} 

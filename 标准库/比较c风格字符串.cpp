#include <iostream>
using namespace std;
#include <cstring>
int main(){
	const char str1[]="hello,world";
	const char str2[]="hello,kitty";
	
	if (strcmp(str1,str2) < 0){
		cout << "str1 is less than str2"<<endl;
	}
	else{
		cout << "str1 is more than str2"<<endl;
	}
		
	cout << str1 << "--" << sizeof(str1)<<endl;
	return 0;
} 

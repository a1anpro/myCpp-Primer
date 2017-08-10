#include <iostream>
using namespace std;

int main(){
	string str;
	string str1;
	
	//geline函数 从cin中读取一行赋给str，返回cin 
	getline(cin,str) >> str1;
	
	cout << str<<endl;
	cout << str1<<endl;
	return 0;
}

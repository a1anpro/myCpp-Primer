#include <iostream>
using namespace std;

int main(){
	string str = "hello,world";
	const char *cstr = str.c_str();
	
	cout << cstr <<endl;
	
	str += ",yanhui";
	cout << str.c_str()<<endl;
	cout << cstr<<endl;//������ԭ�����ǿ����������� 
	return 0;
}

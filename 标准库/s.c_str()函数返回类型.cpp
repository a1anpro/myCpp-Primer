#include <iostream>
using namespace std;

int main(){
	string str = "hello,world";
	const char *cstr = str.c_str();
	
	cout << cstr <<endl;
	
	str += ",yanhui";
	cout << str.c_str()<<endl;
	cout << cstr<<endl;//到底是原件还是拷贝件？疑问 
	return 0;
}

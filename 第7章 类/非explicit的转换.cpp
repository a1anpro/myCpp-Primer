#include <iostream>
using namespace std;
#include <vector> 
int main(){
	char chr = 'x';
	const char *pc = &chr;
	//string str = (const char*)('x');//用这种形式的强制转换和const_cast/static_cast有什么区别。 
	//string str = pc;//string 接受一个单参数的const char*的string构造函数不是explicit的，所以可以用拷贝形式的初始化 
	string str = "hello";//const char*就是c语言风格的字符串，能够用单参数的非explicit的构造函数很自然。 
	cout << str<<endl;
	
	vector<int> vi(10);//接受一个容量参数的vector构造函数是explicit的，所以必须直接初始化。 
	return 0;
}

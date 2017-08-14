#include <iostream>
using namespace std;

int num = 1;
struct Number{
	Number(){
		mysn = num++;
	}
	Number(const Number &rhs){
		mysn = num++;
		cout << "拷贝构造函数" <<endl;
	}
	int mysn;
};

void f(Number a){
	cout << a.mysn <<endl;
}

int main(){
	Number a, b=a;//这是调用了拷贝构造函数，也可以绕过拷贝构造函数，直接使用匹配的构造函数 
	return 0;
}

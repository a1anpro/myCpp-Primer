#include <iostream>
using namespace std;

int main(){
	int a = 10;

	decltype(&a) b = &a;
	auto c = &a;//c仍然是指针 
	cout << *c << endl;; 

//--------------------------
	int d = 10, &r = d;//b是int，r是引用b
	auto e = r;//e是int
	decltype(r) f = d;
	
	e = 100;
	cout << d <<endl;
	f = 100;//果然可以证明f是引用。所以说 decltype得到的是具体的，auto是往下钻了的 
	cout << d <<endl;
	 
	return 0;
}

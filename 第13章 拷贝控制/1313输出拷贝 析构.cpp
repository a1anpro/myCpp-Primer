#include <iostream>

using namespace std;

struct X{
	X(){
		cout << "X()" <<endl;
	}
	X(const X&){ 
		cout << "X(const X)" <<endl;
	}
	~X(){
		cout << "~X()" <<endl;
	}
};

int main(){
	X x;
	X y(x);
	X *t = new X;
	delete t;
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	int temp = 10;
	const int a = temp;
	auto &b = a;
	
	b = 2;
	cout << b;
	return 0;
}



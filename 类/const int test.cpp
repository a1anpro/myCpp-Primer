#include <iostream>
using namespace std;

int main(){
	
	int a = 10;
	const int &r = a;
	const int *p = &a;
	const int *const cp = &a;//非常量可以提升为常量 
	return 0;
}

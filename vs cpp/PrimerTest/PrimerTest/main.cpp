#include <iostream>
using namespace std;

int main() {
	int a = 10;
	const int &r = a;
	const int *p = &a;
	const int *const cp = &a;
	return 0;
}
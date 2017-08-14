#include <iostream>
using namespace std;

int func(int a)
{
	auto add = [a](int b){
		return a+b;
	};
	
	return add(1);
}

int main()
{
	cout << func(1);
	return 0;
}

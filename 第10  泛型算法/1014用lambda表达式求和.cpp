#include <iostream>
using namespace std;

int main()
{
	auto add = [](int a, int b){return a+b;};
	cout << add(1,2)<<endl;
	return 0;
}

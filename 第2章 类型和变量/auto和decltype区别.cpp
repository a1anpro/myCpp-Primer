#include <iostream>
using namespace std;

int main(){
	int i = 0,&r = i;
	
	//same
	//auto a = i;
	//decltype(i) b = i;
	
	//different
	auto a = r;
	decltype(r) b = r;
	
	a = 10;
	cout << i <<endl;
	b = 10;
	cout << i <<endl;
	
	return 0;
}

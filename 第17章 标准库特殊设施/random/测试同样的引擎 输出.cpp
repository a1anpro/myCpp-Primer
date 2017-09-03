#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main(){
	default_random_engine e(10);
	uniform_int_distribution<> b(1, 100);
	cout << b(e)<<endl;
	
	default_random_engine e1(10);
	uniform_int_distribution<> b1(1, 100);
	cout << b1(e1)<<endl;
	
	return 0;
}

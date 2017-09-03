#include <iostream>
using namespace std;
#include <random>

int main(){
	default_random_engine e;
	
	cout << e.max() <<endl;
	cout << e.min() <<endl;
	
	return 0;
}

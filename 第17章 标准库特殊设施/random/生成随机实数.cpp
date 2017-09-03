#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main(){
	
	default_random_engine e;
	uniform_real_distribution<double> u(0,1);
	
	for (size_t i = 0; i < 3; ++i){
		cout << u(e)<<endl;
	}
		
	return 0;
}

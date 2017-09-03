#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main(){

	default_random_engine e(time(0));
	uniform_int_distribution<unsigned> u(0, 100);
	
	e.seed(21474836465);//溢出了，传的参数太大；应该是： 0~2147483646 
	
	for (size_t i = 0; i != 10; ++i){
		cout << u(e) <<endl;
	}

	return 0;
}

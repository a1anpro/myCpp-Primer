#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;
int main(){
	default_random_engine e(time(0));
	uniform_int_distribution<unsigned> u(0, 100);
	vector<int> v(100), v1(100);
	
	for (size_t i = 0; i < 100; ++i){
		v.push_back(u(e));
		v1.push_back(u(e));
	}

	if (v1 == v){
		cout << 1<<endl;
	}

	return 0;
}

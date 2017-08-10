#include <iostream>
#include <memory>

using namespace std;

int main(){
	shared_ptr<int> sp(new int[10],[](int *p){delete [] p;});
	
	for (size_t i = 0; i != 10; ++i){
		*(sp.get() + i) = i;
	}
	
	for (size_t i = 0; i!=10; ++i) cout << *(sp.get()+i)<<" ";
	
	sp.reset();
	return 0;
}

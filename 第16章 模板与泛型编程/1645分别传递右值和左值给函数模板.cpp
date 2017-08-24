#include <iostream>
using namespace std;
#include <vector>
template<typename T>
void f(T &&t){
	vector<T> v;
}

int main(){
	//f(42);
	
	int a = 10;
	f(a);
	
	return 0;
}

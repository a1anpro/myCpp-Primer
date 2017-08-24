#include <iostream>
#include <functional>
using namespace std;

template<typename T>
int compare(const T &lhs, const T &rhs){
	if (less<T>()(lhs, rhs)) return 1;
	else if (less<T>()(rhs, lhs)) return -1;
	else return 0;
}

int main(){
	int a=10, b=20;
	
	cout << compare(a,b);
	
	return 0;
} 

#include <iostream>
using namespace std;

template<typename T, unsigned N>
void print(const T (&t)[N]){
	for (auto i:t){
		cout << i <<" ";
	}
}

int main(){
	int a[10] ={1,2,3,4,5,6,7,8,9,10};
	
	print(a);
	
	return 0;
}

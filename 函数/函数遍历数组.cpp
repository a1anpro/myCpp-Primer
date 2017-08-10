#include <iostream>
using namespace std;

void print(const int (&a)[5]){
	for (auto t : a){
		cout << t<<endl;
	}
}

int main(){
	int a[] = {1,2,3,4,5};
	print(a);
	
	return 0;
}

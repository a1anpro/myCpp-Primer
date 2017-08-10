#include <iostream>
using namespace std;

int main(){
	int i = 42;
	int &r1 = i;
	const int &r2 = i;
	
	cout << "r1:" << r1<<endl;
	cout << "r2:" << r2<<endl;
	
	cout <<"-----------------------"<<endl;
	
	r1 = 0;
	cout << "r1:" << r1<<endl;
	cout << "r2:" << r2<<endl;

	return 0;	
}


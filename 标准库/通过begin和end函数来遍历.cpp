#include <iostream>
using namespace std;

int main(){
	int a[10]={1,23,4,5,6,7,8};
	int *beg = begin(a);
	int *last = end(a);
	
	for (;beg!=last;++beg){
		cout << *beg <<endl;
	}	
	return 0;
} 

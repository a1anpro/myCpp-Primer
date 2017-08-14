#include <iostream>
using namespace std;

void swap(int *&p1, int *&p2){
	auto t = p1;
	p1 = p2;
	p2 = t;
}

int main(){
	int i=42,j=24;
	auto pi = &i;
	auto pj = &j;
	
	swap(pi,pj);
	
	cout << *pi<<endl;
	cout << *pj<<endl;
	
	return 0;
}

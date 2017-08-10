#include <iostream>
using namespace std;

int main(){
	int ia[10]={0};
	int size = sizeof(ia)/sizeof(int);
	cout << size<<endl;
	//decltype(ia)得到的是数组，auto ia得到的是指针。 
	return 0;
}

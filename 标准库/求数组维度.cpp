#include <iostream>
using namespace std;

int main(){
	int ia[10]={0};
	int size = sizeof(ia)/sizeof(int);
	cout << size<<endl;
	//decltype(ia)�õ��������飬auto ia�õ�����ָ�롣 
	return 0;
}

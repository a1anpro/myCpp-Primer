#include <iostream>

using  namespace std;

int main(){
	const int i = 42;
	
	auto &k = i;//k ��һ�����γ������� 
	auto h = i;
	h = 10;//��ʵ֤��h��int 
	cout << h <<endl;
	cout << k<<endl; 
	
	return 0;
} 

#include <iostream>
using namespace std;

int main(){
	int a = 10;

	decltype(&a) b = &a;
	auto c = &a;//c��Ȼ��ָ�� 
	cout << *c << endl;; 

//--------------------------
	int d = 10, &r = d;//b��int��r������b
	auto e = r;//e��int
	decltype(r) f = d;
	
	e = 100;
	cout << d <<endl;
	f = 100;//��Ȼ����֤��f�����á�����˵ decltype�õ����Ǿ���ģ�auto���������˵� 
	cout << d <<endl;
	 
	return 0;
}

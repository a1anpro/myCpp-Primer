#include <iostream>
using namespace std;

int main(){
	cout << unitbuf;//����ostream��cout����ÿ��д����֮�󶼽���һ��flush��������nounitbuf������������ 
	cout << "hi" << endl;
	cout << "hi" << ends;//ˢ�»������������һ���ո�� 
	cout << "hi" << flush;//ˢ�²������κ��ַ� 
	return 0;
}

#include <iostream>
using namespace std;
int main(){
	typedef char *pstring;
	const pstring ps = 0;//ps��ָ��char�ĳ���ָ��
	
	char chr = 'a';
	const pstring *ps = 0; 
	
	
	if (ps==nullptr){
		cout << "ps is empty" <<endl;
	}
	
	return 0;
}

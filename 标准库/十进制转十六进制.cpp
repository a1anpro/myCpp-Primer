#include <iostream>
using namespace std;

int main(){
	const string hexDigits = "0123456789ABCDEF";
	cout << "����0-15֮���ʮ�������֣�����ת����ʮ�����Ƶ�����"<<endl;
	
	string result;
	string::size_type n;//�û������ʮ������
	
	while (cin >> n){
		if (n < hexDigits.size()){
			result += hexDigits[n];
		}
	} 
	
	cout << "hex:" <<result<<endl;
	return 0;
}

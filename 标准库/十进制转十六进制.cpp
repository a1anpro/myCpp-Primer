#include <iostream>
using namespace std;

int main(){
	const string hexDigits = "0123456789ABCDEF";
	cout << "输入0-15之间的十进制数字，将会转换成十六进制的数字"<<endl;
	
	string result;
	string::size_type n;//用户输入的十进制数
	
	while (cin >> n){
		if (n < hexDigits.size()){
			result += hexDigits[n];
		}
	} 
	
	cout << "hex:" <<result<<endl;
	return 0;
}

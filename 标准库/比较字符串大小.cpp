#include <iostream>
using namespace std;

int main(){
	
	string str1, str2;
	
	cin >> str1 >> str2;
	if (str1!=str2){
		if (str1>str2) cout << str1<<endl;
		else cout << str2<<endl;
	} 
	
	cout <<"�Ƚϳ���:"<<endl;
	
	if (str1.size() != str2.size()){
		if (str1.size()>str2.size()){
			cout << str1<<endl;
		}
		else cout << str2<<endl;
	}
	return 0;
} 

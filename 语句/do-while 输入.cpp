#include <iostream>
using namespace std;

int main(){
	string a,b;
	do{
		cout <<"input 2 strings:"<<endl;
		cin >> a>> b;
		if (a.size()<b.size()){
			cout << a<<endl;
		}
		else{
			cout << b<<endl;
		}
		a=b="";
	} 
	while (cin);
	return 0;
} 

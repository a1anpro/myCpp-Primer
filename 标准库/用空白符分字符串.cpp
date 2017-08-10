#include <iostream>
using namespace std;
int main(){
	
	string largeStr;
	string str;
	
	while (cin >> str){
		if (!largeStr.empty()){
			largeStr += ' ' + str;
		}
		else{
			largeStr += str;
		}
	}
	
	
	cout << "largestr:" <<endl;
	
	cout << largeStr<<endl;
	return 0;
}

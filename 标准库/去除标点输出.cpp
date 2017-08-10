#include <iostream>
using namespace std;
#include <cctype>
int main(){
	string str;
	
	while (getline(cin,str)){
		for (auto c : str){
			if (!ispunct(c)) cout << c;
		}
	}
	
	return 0;
}

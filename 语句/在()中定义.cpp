#include <iostream>
using namespace std;

int main(){
	string str = "hello";
	string::iterator iter = str.begin();
	while (iter != str.end()){
		++iter;
	}
	return 0;
} 

#include <iostream>
using namespace std;

int main(){
	string str = "hello,world";
	
	string::size_type index = 0;
	while (index < str.size()){
		str[index] = 'x';
		++index;
	}
	
	cout << str <<endl;
	
	for (index=0;index<str.size(); ++index){
		str[index] = 'y';
	}
	cout << str<<endl;
	return 0;
}

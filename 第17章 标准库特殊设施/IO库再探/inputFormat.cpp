#include <iostream>
using namespace std;
int main(){
	
	cin >> noskipws;
	int i = 0;
	char ch;
	while (cin >> ch){
		++i;
		cout << ch;
	}
	cout << i;
	return 0;
}

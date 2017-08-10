#include <iostream>
#include <cctype>
using namespace std;
#include <vector>

int main(){
	vector<string> v;
	string temp;
	
	while (cin >> temp){
		for (auto &c:temp){
			c=toupper(c);
		}
		v.push_back(temp);
	}
	
	for (auto word:v){
		cout << word <<endl;
	}
	return 0;
}

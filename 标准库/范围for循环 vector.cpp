#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<char> v;
	string str = "hello,wrodl";
	for (auto c : str){
		v.push_back(c);
	}	
	cout << v.size()<<endl;	
	return 0;
}

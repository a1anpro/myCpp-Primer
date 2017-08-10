#include <iostream>
using namespace std;
#include <vector>
int main(){
	vector<int> v(10);
	
	for (decltype(v.size()) i = 0; i != 10; ++i){
		v[i] = i;
	}
	for (auto &c : v){
		c = c*2;
	}
	
	for (auto c:v){
		cout << c <<endl;
	}
	cout << v.size()<<endl;
	return 0;
}

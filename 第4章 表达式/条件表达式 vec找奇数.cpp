#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<int> vec{1,2,3,4,5,6,7,8,9};
	for (auto &v : vec){
		v = v%2!=0?2*v:v;
	}	
	
	for (auto v:vec){
		cout << v <<endl;
	}
	
	return 0;
} 

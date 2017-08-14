#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main(){
	vector<int> vi(10);
	fill_n(vi.begin(), 10, 99);
	for(auto i:vi){
		cout << i<<endl;
	}	
	return 0;
} 

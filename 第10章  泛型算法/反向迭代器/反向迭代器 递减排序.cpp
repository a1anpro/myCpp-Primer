#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
int main(){
	vector<int> vi={1,5,2,3,4,77,45,2};
	
	sort(vi.begin(), vi.end());
	for(auto i:vi)cout<< i<<" ";	
	cout <<endl;
	sort(vi.rbegin(), vi.rend());
	for(auto i:vi)cout<< i<<" ";	
	
	return 0;
}

#include <iostream>
using namespace std;
#include <vector>
int main(){
	vector<int> v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	
	int sought = 4;
	auto beg = v.begin(), end=v.end();
	auto mid = beg+(end-beg)/2;
	while (mid != end && *mid == sought){
		if (*mid < sought){
			beg = mid+1;
		}
		else{
			end = mid;
		}
		mid = beg + (end-beg)/2;
	}
	
	cout << mid - v.begin();
	return 0;
} 

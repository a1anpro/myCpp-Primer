#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> nums;
	int temp;
	while (cin >> temp){
		nums.push_back(temp);
	}
	
	decltype(nums.size()) size = nums.size();
	if (size%2!=0){
		//ÆæÊý¸ö
		size = size/2+1; 
	}
	else{
		size /= 2;
	}
	for (decltype(size) i = 0; i < size; ++i){
		cout << nums[i] + nums[nums.size()-i-1] <<endl;
	}
	return 0;
}

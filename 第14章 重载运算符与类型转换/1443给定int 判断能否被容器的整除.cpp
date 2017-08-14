#include <iostream>
#include <functional>
using namespace std;
#include <vector>
#include <algorithm>
int main(){
	vector<int> vec{2,4,6,8};
	
	int input;
	cin >> input;
	modulus<int> mod;
	auto predicator = [&](int i){
		return 0 == mod(input, i);
	};	//隐式捕获变量的lambda
	 
	auto is_divisible = any_of(vec.begin(), vec.end(), predicator);
	cout << (is_divisible?"yes":"no")<<endl;
	
	return 0;
}

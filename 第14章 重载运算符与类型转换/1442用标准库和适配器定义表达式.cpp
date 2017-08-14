#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

int main(){
	vector<int> vec{100,2,3,1,44,221,3213,444};
	vector<string> vstr{"hello", "bike", "yanhui"};
	auto cnt = count_if(vec.begin(), vec.end(), bind(greater<int>(), _1,200));//greater<int>()是标准库中的可调用对象,传入两个参数来比较大小 
	//cout << cnt<<endl;
	auto find = find_if(vstr.begin(), vstr.end(), bind(not_equal_to<string>(), _1, "hello"));
	//cout << *find<<endl;	

	transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(),_1,2));
	//transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), _1, 2));	
	for (const auto &i:vec){
		cout << i<<endl;
	}
	return 0;
}

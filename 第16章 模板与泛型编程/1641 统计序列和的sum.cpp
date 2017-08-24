#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

template<typename It>
auto sum(It beg, It end)->typename remove_reference<decltype(*beg)>::type{
	typename remove_reference<decltype(*beg)>::type sum = 0;//得到sum的类型
	
	for (; beg != end; ++beg){
		sum += *beg;
	}
	
	return sum; 
}

int main(){
	vector<int> v{1,2,3,4,5};
	
	cout << sum(v.begin(), v.end());
	
	return 0;
}

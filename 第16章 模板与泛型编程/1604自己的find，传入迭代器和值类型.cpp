#include <iostream>
using namespace std;
#include <vector>
template<typename Input, typename T>//类型参数
Input find(Input begin, Input end, const T &t){
	for (;begin!=end; ++begin){
		if (*begin==t) return begin;
	}
	return end;
} 

int main(){
	vector<int> v{1,2,3,4,5,6,6};
	cout << find<vector<int>::iterator, int>(v.begin(), v.end(), 3) - v.begin();
	return 0;
}

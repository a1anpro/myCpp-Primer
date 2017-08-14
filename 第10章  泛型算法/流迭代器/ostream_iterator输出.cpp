#include <iostream>
using namespace std;
#include <iterator>
#include <vector>

int main(){
	vector<int> vi={1,2,3,4,5};
	ostream_iterator<int> out_iter(cout, " ");
	
	for (auto i:vi){
		*out_iter++ = i;//等价于out_iter=i; 
	}
	
	//换个写法
	copy(vi.begin(), vi.end(), out_iter);//将vi从begin到end拷贝到out_iter
	 
	return 0;
} 

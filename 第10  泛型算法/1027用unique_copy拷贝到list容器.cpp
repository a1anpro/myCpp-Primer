#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vi={1,2,3,4,5,1,1,1,2};
	list<int> li;
	sort(vi.begin(),vi.end());
	
	auto it = unique_copy(vi.begin(), vi.end(), back_inserter(li));//第三个参数是目的位置迭代器，因为li是空的，我们必须向里面插入元素。所以要插入迭代器 
	for(auto i:li)cout << i<<" ";
	cout <<endl;
	auto it2 = unique(vi.begin(), vi.end());
	for (auto i:vi){
		cout << i << " ";
	}
	return 0;
}

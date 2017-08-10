#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <list>
int main(){
	vector<int> vi={1,2,0,3,4,3,5,6,7};
	
	for (auto ix=vi.crbegin(); ix!=vi.crend(); ++ix){
		cout << *ix << " ";
	}
	cout << endl;
	
	for (auto ix=vi.cend(); ix!=vi.cbegin();)
	{
		cout << *--ix<<" ";
	}
	cout << endl;
	auto ix = find(vi.crbegin(), vi.crend(), 0);
	cout << *ix << " in front of "<< *ix.base()<<endl;
	
	cout <<endl;
	
	list<int> li;
	copy(vi.crbegin()+3, vi.crbegin()+8, back_inserter(li));//因为迭代器都是左闭右开的，所以从第三个要拷贝到第七个，需要将结尾设置为8 
	for (auto i:li)cout << i << " ";
	
	return 0;	
}

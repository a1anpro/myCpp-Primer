#include <iostream>
using namespace std;
#include <vector>
#include <list>

int main(){
	int ia[] = {1,2,3,4,5,6,7,8,9,0};
	vector<int> vi;
	list<int> li;
	
	//vector<int> vi(ia,end(ia));
	//list<int> li(vi.begin(), vi.end());//用构造函数来初始化，为什么不能用for 
	
	for (auto i:ia){
		vi.push_back(i);
		li.push_back(i);
	}	
	
//	for (auto iter = vi.begin(); iter!=vi.end(); ++iter){
//		if (!(*iter & 0x1))
//		{
//			//偶数就删除
//			vi.erase(iter);//返回的是void 
//		}
//	}
	auto iter = vi.begin();
	while (iter!=vi.end())
	{
		if (!(*iter & 0x1))
		{
			vi.erase(iter);//删除之后，迭代器往后移动了 
		}
		else{
			++iter;
		}
	}
	
	auto it = li.begin();
	while (it!=li.end())
	{
		if (*it&0x1)
		{
			li.erase(it);
		}
		{
			++it;
		}
	}
	
	for (auto i:vi){
		cout << i <<" ";
	}
	cout <<endl;
	for (auto i:li)
	{
		cout << i <<" ";
	}
	return 0;
}

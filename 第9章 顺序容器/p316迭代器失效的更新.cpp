#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <forward_list>
int main(){
	list<int> vi = {1,2,3,4,5,6,7};
	//复制奇数，删除偶数
	auto iter = vi.begin();//要改变vi
	
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			//复制奇数，插入到当前元素的前面
			iter = vi.insert(iter, *iter);//插入会使当前的迭代器失效，所以插入完了之后要更新迭代器 
			//iter += 2;//迭代器再更新后指向当前元素。要访问未访问的元素需要向后走两个单位 
			advance(iter,2);
		}
		else
		{
			//删除偶数
			iter = vi.erase(iter);//删除所指的iter，返回的是删除后的一个元素的迭代器。 
		}
	} 
	
	for (const auto &i : vi)
	{
		cout << i << " ";
	}
	
	return 0;
}

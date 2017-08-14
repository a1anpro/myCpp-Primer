#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <forward_list>
int main(){
	forward_list<int> fli = {1,2,3,4,5,6,7};
	//复制奇数，删除偶数
	//要插入必须要得到当前元素的首前迭代器
	auto prev = fli.before_begin();
	auto beg = fli.begin();
	while (beg != fli.end())
	{
		if (*beg % 2)
		{
			beg = fli.insert_after(prev, *beg);//插入后要更新beg，将beg指向当前插入元素的迭代器；
			++beg;++beg;//移动到没有访问的元素 
			++prev;++prev;//可以用函数advance(iter,2); 
		}
		else
		{
			beg = fli.erase_after(prev);
		}
	}
	
	for (const auto &i : fli)
	{
		cout << i << " ";
	}
	
	return 0;
}

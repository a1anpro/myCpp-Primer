#include <iostream>
#include <forward_list>
using namespace std;

int main(){
	forward_list<int> fli{1,2,3,4,5,6,7,8};
	//删除奇数元素
	auto prev = fli.before_begin();//得到首前迭代器
	auto curr = fli.begin();//得到fli的第一个元素的迭代器
	
	while (curr!=fli.end())
	{
		if (*curr & 0x1){
			//奇数就删除,传首前元素迭代器
			curr = fli.erase_after(prev);//首前迭代器不变，curr移动到删除后的元素 
		}
		else{
			prev = curr;//保存当前位置，curr向前移动
			curr++; 
		}
	} 
	for (const auto &i:fli){
		cout << i<<endl;
	}
	return 0;
}

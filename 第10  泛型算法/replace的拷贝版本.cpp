#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	//拷贝版本比非拷贝版本要多一个 接收额外第三个迭代器参数
	vector<int> v1={1,2,3,4,5,1,1,1};
	vector<int> v2;
	//因为v2是空容器，我们用插入迭代器来push元素。 
	replace_copy(v1.cbegin(), v1.cend(), back_inserter(v2), 1, 99);
	for (auto i:v2)cout << i<<" "; 
	return 0;
}

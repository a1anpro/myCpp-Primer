#include <iostream>
using namespace std;

//initializer_list也是有beg和end的 可以迭代。
//il的元素都是const类型的。 
int sum(initializer_list<int> il){
	int total = 0;
	for (const auto &i : il){
		total += i;
	}
	return total;
}

int main(){
	cout << sum({1,2,3,4,5});
	
	return 0;
}

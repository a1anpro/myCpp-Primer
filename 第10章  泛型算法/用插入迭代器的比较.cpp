#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int main(){
	list<int> lst={1,2,3,4};
	list<int> lst1, lst2;//空的 
	
	copy(lst.begin(), lst.end(), front_inserter(lst1));//通过front_inserter得到插入迭代器，每次调用push_front
	copy(lst.begin(), lst.end(), inserter(lst2, lst2.begin()));//插入后的当前位置没有变。虽然lst2的begin已经变了。 
	
	for (auto i:lst1)cout << i<<" ";
	cout << endl;
	for (auto i:lst2)cout << i<<" ";
	
	return 0;
}

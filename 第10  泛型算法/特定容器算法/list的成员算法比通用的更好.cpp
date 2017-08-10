#include <iostream>
#include <list>

using namespace std;

int main(){
	list<int> li={1,2,3,1,2,3};
	li.sort();
	li.unique();
	for(auto i:li)cout << i<<" ";
	return 0;
} 

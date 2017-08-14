#include <iostream>
using namespace std;
#include <vector>
#include <list>
int main(){
	vector<int> a{1};
	//cout << a.reserve(100)<<endl;
	cout << a.capacity()<<endl;
	//cout << a.max_size()<<endl;
//	int ia[]={1,2,3,4};
//	list<int> li;
//	vector<int> vi;
//	
//	for (auto i:ia){
//		vi.push_back(i);
//		li.push_back(i);
//	}
//	for (auto i:li){
//		cout << i<<endl;
//	}
//	for (auto i:vi){
//		cout << i<<endl;
//	}
	return 0;
}

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <list>
int main(){
	vector<int> vi={1,1,1,42,3,4,1,1,5,1};
	int val = 1;
	
	cout << count(vi.begin(), vi.end(), val) <<endl;
	
	list<string> vstr={"hello", "yanhui" ,"hello"};
	cout<< count(vstr.begin(), vstr.end(), "hello")<<endl;
	return 0;
}

#include <iostream>
#include <deque>
#include <list>
using namespace std;

int main(){
	list<int> li={1,2,3,4,5,6,7};
	deque<int> odd, even;
	for (const auto &i : li){
//		if (i%2==0) even.push_back(i);//牛逼一点的判断偶数 i&0x1  偶数的最后一个bit是0， 
//		else odd.push_back(i);
		(i&0x1?odd:even).push_back(i);//666
	}
	
	for (const auto &i:odd){
		cout << i <<" ";
	}
	cout << endl;
	for (const auto &i:even){
		cout << i <<" ";
	}
	return 0;
}

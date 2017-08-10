#include <iostream>
#include <deque>
#include <list>
using namespace std;

int main(){
	string str;
	//deque<string> deq;
	list<string> deq;
	while (cin >> str)
	{
		deq.push_back(str);
	}	
	for (auto iter = deq.begin(); iter!=deq.end(); ++iter)
	{
		cout << *iter<<endl;
	}
	
	return 0;
}

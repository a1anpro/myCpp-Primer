#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<int> vi(2,9);
	
	if (!vi.empty())
	{
		cout << vi[0]<<endl;
		cout << vi.at(0) <<endl;
		cout << vi.front() <<endl;//��Ա�������ص�������
		cout << *vi.begin()<<endl; 
	}
	
	return 0;
}

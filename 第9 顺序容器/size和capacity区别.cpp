#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> vi;
	vi.reserve(50);
	cout<<"size:" << vi.size()<<endl;
	cout << "capacity:" << vi.capacity() <<endl;
	
	for (vector<int>::size_type ix = 0; ix != 54; ++ix)
	{
		vi.push_back(ix);
	}
		
	cout<<"size:" << vi.size()<<endl;
	cout << "capacity:" << vi.capacity() <<endl;

	cout << "after shrink_to_fit:"<<endl;
	vi.shrink_to_fit();
	cout<<"size:" << vi.size()<<endl;
	cout << "capacity:" << vi.capacity() <<endl;

	return 0;
}

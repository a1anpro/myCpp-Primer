#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <list>
int main(){
	vector<int> vi={1,2,0,3,4,3,5,6,7};
	
	for (auto ix=vi.crbegin(); ix!=vi.crend(); ++ix){
		cout << *ix << " ";
	}
	cout << endl;
	
	for (auto ix=vi.cend(); ix!=vi.cbegin();)
	{
		cout << *--ix<<" ";
	}
	cout << endl;
	auto ix = find(vi.crbegin(), vi.crend(), 0);
	cout << *ix << " in front of "<< *ix.base()<<endl;
	
	cout <<endl;
	
	list<int> li;
	copy(vi.crbegin()+3, vi.crbegin()+8, back_inserter(li));//��Ϊ��������������ҿ��ģ����Դӵ�����Ҫ���������߸�����Ҫ����β����Ϊ8 
	for (auto i:li)cout << i << " ";
	
	return 0;	
}

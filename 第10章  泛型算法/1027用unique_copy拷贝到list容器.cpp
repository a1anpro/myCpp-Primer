#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vi={1,2,3,4,5,1,1,1,2};
	list<int> li;
	sort(vi.begin(),vi.end());
	
	auto it = unique_copy(vi.begin(), vi.end(), back_inserter(li));//������������Ŀ��λ�õ���������Ϊli�ǿյģ����Ǳ������������Ԫ�ء�����Ҫ��������� 
	for(auto i:li)cout << i<<" ";
	cout <<endl;
	auto it2 = unique(vi.begin(), vi.end());
	for (auto i:vi){
		cout << i << " ";
	}
	return 0;
}

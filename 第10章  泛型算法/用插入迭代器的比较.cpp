#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int main(){
	list<int> lst={1,2,3,4};
	list<int> lst1, lst2;//�յ� 
	
	copy(lst.begin(), lst.end(), front_inserter(lst1));//ͨ��front_inserter�õ������������ÿ�ε���push_front
	copy(lst.begin(), lst.end(), inserter(lst2, lst2.begin()));//�����ĵ�ǰλ��û�б䡣��Ȼlst2��begin�Ѿ����ˡ� 
	
	for (auto i:lst1)cout << i<<" ";
	cout << endl;
	for (auto i:lst2)cout << i<<" ";
	
	return 0;
}

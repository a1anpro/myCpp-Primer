#include <iostream>
using namespace std;

//initializer_listҲ����beg��end�� ���Ե�����
//il��Ԫ�ض���const���͵ġ� 
int sum(initializer_list<int> il){
	int total = 0;
	for (const auto &i : il){
		total += i;
	}
	return total;
}

int main(){
	cout << sum({1,2,3,4,5});
	
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	//�����汾�ȷǿ����汾Ҫ��һ�� ���ն������������������
	vector<int> v1={1,2,3,4,5,1,1,1};
	vector<int> v2;
	//��Ϊv2�ǿ������������ò����������pushԪ�ء� 
	replace_copy(v1.cbegin(), v1.cend(), back_inserter(v2), 1, 99);
	for (auto i:v2)cout << i<<" "; 
	return 0;
}

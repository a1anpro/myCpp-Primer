#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<string> v1;//empty
	{
		vector<string> v2={"hello","world"};
		v1=v2;
	}
	//cout << v2.size();
	cout << v1.size()<<endl;//v2����������ͱ�����/v2��Ԫ��Ҳ�����ġ�������˵��v1��v2��Ԫ�����໥����ġ�
	 
	return 0;
}

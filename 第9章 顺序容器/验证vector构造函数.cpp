#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<int> v={1,2,3};
	vector<int> v1{1,2,3};
	vector<int> v2;
	vector<int> v3(10);//explicit�ĺ�������ֻ��һ�����������ܿ�������ֻ��ֱ�ӳ�ʼ�����졣
	//explicit��Ϊ�����ƹ��캯����ʽת��������ġ� 
	vector<int> v4(10,1);
	//...
	//ֻ��vector����һ�����������Ĺ��캯����explicit�� 
	
	
	return 0;
}

#include <iostream>
using namespace std;
#include <vector> 
int main(){
	char chr = 'x';
	const char *pc = &chr;
	//string str = (const char*)('x');//��������ʽ��ǿ��ת����const_cast/static_cast��ʲô���� 
	//string str = pc;//string ����һ����������const char*��string���캯������explicit�ģ����Կ����ÿ�����ʽ�ĳ�ʼ�� 
	string str = "hello";//const char*����c���Է����ַ������ܹ��õ������ķ�explicit�Ĺ��캯������Ȼ�� 
	cout << str<<endl;
	
	vector<int> vi(10);//����һ������������vector���캯����explicit�ģ����Ա���ֱ�ӳ�ʼ���� 
	return 0;
}

#include <iostream>
using namespace std;

template<typename T>
int compare(const T&, const T&){
}

void func(int(*)(const string&, const string&)){}
void func(int(*)(const int&, const int&)){}//���غ��������ܵĲ���Ϊ����ָ�룡 

int main(){
	int (*pf)(const int&, const int&) = compare;//pf��һ������ָ�룬ָ��compare,��compare��һ������ģ�壬������pf�еĲ���������T��ģ��ʵ�ε�����
	//T������Ϊint��ָ��pfָ��compare��int�汾ʵ��������
	
	//func(compare);//���ڲ���ȷ��func��ʵ�ε�Ψһ�汾ʵ�������������Գ��� 
	
	func(pf);
	//func(compare<int>);

	return 0;
}

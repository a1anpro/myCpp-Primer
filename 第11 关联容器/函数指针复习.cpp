#include <iostream>

using namespace std;

bool compare(const string &s1, const string &s2){
	return true;
}

typedef bool (*Funcp)(const string&, const string&);//�������ڽ��ܵ��ö���ĵĺ����� 
typedef decltype(compare) Func2;//Ҳ�Ǻ������͵ı�����

void test1(Func2){//!!!!��Ȼ����ָ������ָ�롣���Ǳ����Զ��Ľ�Func2��Func��ʾ�ĺ�������ת����ָ�롣 
	
}
void test(Funcp fc) {//���ܿɵ��ö���ָ�������ָ��ʵ�δ����� ���� 
	
}

int main(){
	bool (*pf)(const string&,const string&)=compare;
	typedef bool Func(const string&, const string&);//ֻ�Ǻ������͵ı������������κκ���
	
	typedef decltype(compare) *dFuncp;//����Ҫָ����*ָ����С���Ϊdecltypeֻ�Ƿ��غ������ͣ���ʱ���Ὣ���������Զ�ת����ָ�����͡�
	//���ʺ����ı�����ʲô�أ���һ����Ϊ����Ϊʲô������ָ����Ϊ��ָ���أ�ָ����ָ���ڴ��ַ�ģ���ô˵�Ļ�������Ҳ�����ڴ��еĶ��󿩣�
	//Ҳ����˵ �����ı��ʾ��Ƕ���ֻ���ô���һ�����ѡ�һ�������������ֵ�ġ�����������Բ����Ĳ����� 

	return 0;
}

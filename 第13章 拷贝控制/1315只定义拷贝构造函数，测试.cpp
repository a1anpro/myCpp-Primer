#include <iostream>
using namespace std;

int num = 1;
struct Number{
	Number(){
		mysn = num++;
	}
	Number(const Number &rhs){
		mysn = num++;
		cout << "�������캯��" <<endl;
	}
	int mysn;
};

void f(Number a){
	cout << a.mysn <<endl;
}

int main(){
	Number a, b=a;//���ǵ����˿������캯����Ҳ�����ƹ��������캯����ֱ��ʹ��ƥ��Ĺ��캯�� 
	return 0;
}

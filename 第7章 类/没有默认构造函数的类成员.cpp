#include <iostream>
#include <vector>
using namespace std;

class NoDefault{
public:
	NoDefault(int i){
	}
};

class C{
public:
	C():nd(0){
	}
	void print(){
		cout << "�������캯��"<<endl;
	}
private:
	NoDefault nd;
};

int main(){
	vector<NoDefault> vec(10,10);//vec(10)�Ǵ�ģ���ΪNoDefault��û��Ĭ�Ϲ��캯���ģ�û�и�vec��ʼֵ�Ͳ��������еĹ��캯�� 
	vector<C> c(10);
	//C c();
	//c.print();//����c�Ǻ��������� ���� 
	return 0;
}

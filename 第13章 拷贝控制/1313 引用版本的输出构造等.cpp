#include <iostream>
#include <vector>
using namespace std;

struct X{
	X(){
		cout << "X()" <<endl;
	}
	X(const X&){ 
		cout << "X(const X)" <<endl;
	}
	X& operator=(const X&){
		cout << "X& operator=(const X&)" <<endl;
		return *this;
	}
	~X(){
		cout << "~X()" <<endl;
	}
};

void f(const X& rx, X x){
	vector<X> vec;
	vec.reserve(2);//Ԥ�ȷ���2���ռ�
	vec.push_back(rx);
	vec.push_back(x); 
}

int main(){
	//X x();//���ǵ��ù��캯���������ǵõ����� 
	X x;
	f(x,x);
	
	return 0;
}

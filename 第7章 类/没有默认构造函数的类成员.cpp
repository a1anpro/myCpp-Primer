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
		cout << "声明构造函数"<<endl;
	}
private:
	NoDefault nd;
};

int main(){
	vector<NoDefault> vec(10,10);//vec(10)是错的，因为NoDefault是没有默认构造函数的，没有给vec初始值就不能用其中的构造函数 
	vector<C> c(10);
	//C c();
	//c.print();//错误，c是函数而不是 对象。 
	return 0;
}

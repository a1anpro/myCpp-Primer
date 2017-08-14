#include <iostream>
#include <memory>
using namespace std;

int main(){
	auto p = make_shared<int>(42);
	auto q(p);//此时p指向的对象有2个计数值
	
	auto r = make_shared<int>(22);
	
	p = r;
	cout << *q<<endl;
	 
	return 0;
}

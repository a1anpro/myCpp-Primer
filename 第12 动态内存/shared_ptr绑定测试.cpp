#include <iostream>
#include <memory>
using namespace std;

int main(){
	auto p = make_shared<int>(42);
	auto q(p);//��ʱpָ��Ķ�����2������ֵ
	
	auto r = make_shared<int>(22);
	
	p = r;
	cout << *q<<endl;
	 
	return 0;
}

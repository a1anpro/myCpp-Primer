#include <iostream>
#include <bitset>
using namespace std;

int main(){
	
	bitset<32> bv(0B1010101);//0bǰ׺��ʾ�Ƕ����Ƴ����� 
	
	cout << bv <<endl;
	cout << bv.count()<<endl;
	cout << bv.size() <<endl;
	cout << "all ?" << bv.all() << endl;
	
	auto bv1 = bv;
	bv1.set();
	cout << bv1.none() << " " <<  bv.none() <<endl;//ȫ����λ�� 
		
	return 0;
}

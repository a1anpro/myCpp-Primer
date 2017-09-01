#include <iostream>
#include <bitset>
using namespace std;

int main(){
	
	bitset<32> bv(0B1010101);//0b前缀表示是二进制常数。 
	
	cout << bv <<endl;
	cout << bv.count()<<endl;
	cout << bv.size() <<endl;
	cout << "all ?" << bv.all() << endl;
	
	auto bv1 = bv;
	bv1.set();
	cout << bv1.none() << " " <<  bv.none() <<endl;//全都置位了 
		
	return 0;
}

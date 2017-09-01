#include <iostream>
#include <bitset>
using namespace std;

int main(){
	
	bitset<32> bv(0xffffffffffffffffffff);
	
	cout << bv <<endl;
	
	cout << bv.to_ulong()<<endl;
	
	return 0;
}

#include <iostream>
#include <bitset>
using namespace std;

int main(){
	constexpr size_t pos[7]{1,2,3,4,8,13,21};
	bitset<32> bv;
	//for (auto pos:{1,2,3,4,8,13,21}
	for (auto i : pos){
		bv.set(i);
	}
	cout << bv<<endl;
	return 0;
}

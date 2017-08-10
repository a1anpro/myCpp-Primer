#include <iostream>
using namespace std;

int main(){
	int ia[] = {1,2,3,4,5,6};
	decltype(ia) ia1;//经过decltype(array)得到的是数组（另外开辟的内存空间）
	cout << sizeof(ia)<<endl;//24 
	cout << sizeof(ia1)<<endl;//24 
	 
	auto ia2 = ia;
	cout << *ia2;//经过auto得到的是数组ia的首地址。 
	
	return 0;
}

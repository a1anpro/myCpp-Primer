#include <iostream>
using namespace std;

int main(){
	int ia[] = {1,2,3,4,5,6};
	decltype(ia) ia1;//����decltype(array)�õ��������飨���⿪�ٵ��ڴ�ռ䣩
	cout << sizeof(ia)<<endl;//24 
	cout << sizeof(ia1)<<endl;//24 
	 
	auto ia2 = ia;
	cout << *ia2;//����auto�õ���������ia���׵�ַ�� 
	
	return 0;
}

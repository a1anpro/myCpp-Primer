#include <iostream>
using namespace std;

int main(){
	int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//��ʼ��	
	using int_array = int[4];//��int_array�������СΪ4��int����
	
	for (int_array *row = ia; row != ia + 3; ++row){
		for (int *col = *row; col != *row + 4; ++col){
			cout << *col << " ";
		}
		cout << endl;
	} 
	
	return 0;
}

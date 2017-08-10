#include <iostream>
using namespace std;

int main(){
	int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//初始化	
	using int_array = int[4];//用int_array来代替大小为4的int数组
	
	for (int_array *row = ia; row != ia + 3; ++row){
		for (int *col = *row; col != *row + 4; ++col){
			cout << *col << " ";
		}
		cout << endl;
	} 
	
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//初始化	
	
	//版本1，用范围for，并且不能用auto
	for (const int (&row)[4] : ia){
		for (int col : row){
			cout << col << " ";
		}
		cout << endl;
	}
	
	//版本2，普通for循环，下标 
	for (size_t row = 0; row != 3; ++row){
		for (size_t col = 0; col != 4; ++col){
			cout << ia[row][col] << " ";
		}
		cout << endl;
	}
	
	//版本3，普通for循环，指针
	for (int (*row)[4] = begin(ia); row != end(ia); ++row){
		for (int *col = begin(*row); col != end(*row); ++col){
			cout << *col << " ";
		}
		cout << endl;		
	} 
	
	using int_array = int[4];//用int_array来代替大小为4的int数组
	
	for (int_array *row = ia; row != ia + 3; ++row){
		for (int *col = *row; col != *row + 4; ++col){
			cout << *col << " ";
		}
		cout << endl;
	} 
	
	for (const auto &cow : ia){
		for (auto col : cow){
			cout << col << " ";
		}
		cout << endl;
	} 
	
	return 0;
}
	//const int (*row)[4] = ia;//ok
//	for (const int (*row)[4] : ia){
//		for (int col : *row){
//			
//		}
//	}
	

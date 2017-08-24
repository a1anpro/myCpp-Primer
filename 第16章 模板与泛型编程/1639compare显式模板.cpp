#include <iostream>

using namespace std;

template<typename T>
int compare(const T& a, const T& b){
	if (a < b){
		return -1;
	}
	else if (a > b){
		return 1;
	}
	return 0;
}

int main(){
	
	cout << compare<string>("caaa", "bbba");//显式模板实参，则可以任意类型转换，传过去的不是数组了:调用的是compare(const string&,const string&) 
	
	return 0;
} 

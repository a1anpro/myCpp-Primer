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
	
	cout << compare<string>("caaa", "bbba");//��ʽģ��ʵ�Σ��������������ת��������ȥ�Ĳ���������:���õ���compare(const string&,const string&) 
	
	return 0;
} 

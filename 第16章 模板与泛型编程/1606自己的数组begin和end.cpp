#include <iostream>

using namespace std;

template<typename T, unsigned N>
T* Begin(T (&arr)[N]){
	return arr;//arr����������ã�arr���������ͷָ�� 
}
template<typename T, unsigned N>
T* End(T (&arr)[N]){
	return arr + N;
}

//1607,���������С
template<typename T, unsigned N>
constexpr unsigned getSize(T (&arr)[N]){
	return N;//N�Ƿ����Ͳ������Ǳ������������Ϊʵ�δ������� 
} 

int main(){
	int arr[3] = {1,2,3};
	
	auto beg = Begin(arr), e = End(arr);
	
	for (;beg!=e; ++beg){
		cout << *beg << " ";
	}
	cout <<endl;
	cout << getSize(arr);
	return 0;
}

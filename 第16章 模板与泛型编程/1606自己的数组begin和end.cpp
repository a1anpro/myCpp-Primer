#include <iostream>

using namespace std;

template<typename T, unsigned N>
T* Begin(T (&arr)[N]){
	return arr;//arr是数组的引用，arr就是数组的头指针 
}
template<typename T, unsigned N>
T* End(T (&arr)[N]){
	return arr + N;
}

//1607,返回数组大小
template<typename T, unsigned N>
constexpr unsigned getSize(T (&arr)[N]){
	return N;//N是非类型参数，是编译器处理后作为实参穿进来的 
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

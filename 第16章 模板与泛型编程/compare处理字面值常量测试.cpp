#include <iostream>
using namespace std;
#include <functional>
#include <cstring>

template<typename T>
int compare(const T &t1, const T &t2){
	if (less<T>()(t1, t2)){
		return -1;
	}
	else if (less<T>()(t2, t1)){
		return 1;
	}
	return 0;
}

 template<unsigned M, unsigned N>
int compare(const char (&s1)[M], const char (&s2)[N]){
	return strcmp(s1, s2);
}

int main(){
	
	//cout << compare(1,2);
	
	//cout << compare("hello", "aaa");//数组为啥不能直接转换成指针? 调用模板2的实例说明了"hello"和"aaa"是const char[]数组,而数组是不能拷贝的，所以只能引用 
	
	const char *s1 = "hello", *s2 = "word";
	cout << compare(s1, s2);
	
	return 0;
}

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
	
	//cout << compare("hello", "aaa");//����Ϊɶ����ֱ��ת����ָ��? ����ģ��2��ʵ��˵����"hello"��"aaa"��const char[]����,�������ǲ��ܿ����ģ�����ֻ������ 
	
	const char *s1 = "hello", *s2 = "word";
	cout << compare(s1, s2);
	
	return 0;
}

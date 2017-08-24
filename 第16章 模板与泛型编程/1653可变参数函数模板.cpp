#include <iostream>
using namespace std;

template<typename T>
ostream& print(ostream &os, const T &t){//���ɱ�����ĺ���ģ��Ҫ��ǰ���������������û����޵ݹ� 
	os << t;
	return os;//Ϊʲôostream���ܿ����� 
}

template<typename T, typename ... Args>
ostream& print(ostream &os, const T &t, const Args&...args){//���ɱ�����ĺ���ģ��Ҫ��ǰ���������������û����޵ݹ� 
	os << t;
	cout << endl;
	return print(os, args...);
}

int main(){
	
	print(cout, 1, 1.2, "hello");
	
	return 0;
}

#include <iostream>
using namespace std;

template<typename T>
int compare(const T&, const T&){
}

void func(int(*)(const string&, const string&)){}
void func(int(*)(const int&, const int&)){}//重载函数，接受的参数为函数指针！ 

int main(){
	int (*pf)(const int&, const int&) = compare;//pf是一个函数指针，指向compare,而compare是一个函数模板，在这里pf中的参数决定了T的模板实参的类型
	//T的类型为int，指针pf指向compare的int版本实例！！！
	
	//func(compare);//由于不能确定func的实参的唯一版本实例化，将二义性出错 
	
	func(pf);
	//func(compare<int>);

	return 0;
}

#include <iostream>
using namespace std;

int main(){
	int i = 0, &r = i;//r是int类型的引用，绑定i
	auto a = r;//a是一个整数，r是i的别名，而i是int
	
	const int ci = i, &cr = ci;//ci是一个int常量，cr是常量引用，绑定的是ci
	auto b = ci;//ci是顶层const被忽略掉，所以b是int类型的普通变量
	auto c = cr;//c是一个整数，cr本身是ci，而ci是顶层const
	auto d = &i;//i是整数，&i是取地址，所以d是指向int的指针（整型的地址就是指向整数的指针）
	auto e = &ci;//e是指向整数常量的指针（ci对常量取地址是一种底层const）
	
	const auto f = ci;//f是const类型的整数
	auto &g = ci;//g是整型常量的引用，绑定到ci
	const auto &j = 42;//可以为常量引用直接绑定字面值
	
	a = 42;
	b = 42;
	c = 42;
	*d = 42;
	e = &ci;//e是指向整数常量的指针 
	
	return 0;
} 

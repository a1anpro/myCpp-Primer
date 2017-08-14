#include <iostream>

using namespace std;

bool compare(const string &s1, const string &s2){
	return true;
}

typedef bool (*Funcp)(const string&, const string&);//可以用在接受调用对象的的函数里 
typedef decltype(compare) Func2;//也是函数类型的别名。

void test1(Func2){//!!!!虽然不是指向函数的指针。但是编译自动的将Func2和Func表示的函数类型转换成指针。 
	
}
void test(Funcp fc) {//接受可调用对象指针参数，指向实参传来的 函数 
	
}

int main(){
	bool (*pf)(const string&,const string&)=compare;
	typedef bool Func(const string&, const string&);//只是函数类型的别名，不代表任何函数
	
	typedef decltype(compare) *dFuncp;//必须要指明是*指针才行。因为decltype只是返回函数类型，此时不会将函数类型自动转换成指针类型。
	//请问函数的本质是什么呢？是一种行为，那为什么可以有指向行为的指针呢？指针是指向内存地址的，这么说的话。函数也是在内存中的对象咯！
	//也就是说 函数的本质就是对象。只是用处不一样而已。一般对象是用来存值的。而函数是针对参数的操作。 

	return 0;
}

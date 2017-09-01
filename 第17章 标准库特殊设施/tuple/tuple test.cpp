#include <iostream>
using namespace std;
#include <tuple>
#include <vector>

int main(){
	
	tuple<string, size_t> t = make_tuple("hello", 0);
	tuple<string, size_t> t1{"hello", 1};
	tuple<size_t, int> t2{1, 2};
	cout << (t1 == t) <<endl;
	cout << (t1 > t) <<endl;
	//如果要比较，则对应的类型必须要定义了比较运算符 
	
	typedef decltype(t) item;//t是一个对象，而tuple_size<>是模板类，需要显式提供类型而不是对象。所以用decltype得到t的类型 
	auto sz = tuple_size<item>::value;
	cout << sz<<endl;
	
	tuple_element<0, item>::type cnt = get<0>(t);
	cout << cnt<<endl;
	
	tuple<int, int, int> tint = make_tuple(10,20,30);
	cout << tuple_size<decltype(tint)>::value <<endl;
	
	tuple<string, vector<string>, pair<string, int>> mul_t = make_tuple("hello", vector<string>{"you", "and", "me"}, make_pair("world", 10));
	cout << tuple_size<decltype(mul_t)>::value<<endl;
	return 0;
} 

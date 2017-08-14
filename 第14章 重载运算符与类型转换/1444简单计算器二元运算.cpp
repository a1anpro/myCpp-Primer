#include <iostream>
#include <functional>
#include <map>
using namespace std;

int add(int a, int b){
	return a+b;
}
struct divide{
	int operator()(int a, int b){
		return a-b;
	}
};

int main(){
	auto mod = [](int a, int b){
		return a%b;
	};
	map<string, function<int(int,int)>> binops{
		{"+", add},
		{"-", minus<int>()},
		{"/", divide()},
		{"*", [](int a, int b){
			return a*b;
		}},
		{"%", mod}//命名了的lambda表达式 
	};
	
	cout << binops["+"](1,2)<<endl;
	
	return 0;
}

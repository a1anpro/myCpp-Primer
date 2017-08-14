#include <iostream>
using namespace std;

int main(){
	int a=10;
	auto lambda = [a]()mutable->bool{//指定了mutable才能让捕获的变量改变 
		while (--a){}
		return a==0;
	};
	//cout << lambda()<<endl;
	
	auto to_zero = [&a]()->bool{
		if (a==0)
		{
			return true;
		}
		else
		{
			--a;
			return false;
		}
	};
	while (!to_zero()){
		cout << a<<endl;
	}
	return 0;
}

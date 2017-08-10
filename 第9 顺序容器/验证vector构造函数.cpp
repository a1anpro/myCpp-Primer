#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<int> v={1,2,3};
	vector<int> v1{1,2,3};
	vector<int> v2;
	vector<int> v3(10);//explicit的函数必须只有一个参数。不能拷贝构造只能直接初始化构造。
	//explicit是为了抑制构造函数隐式转换而创造的。 
	vector<int> v4(10,1);
	//...
	//只有vector接受一个容量参数的构造函数是explicit的 
	
	
	return 0;
}

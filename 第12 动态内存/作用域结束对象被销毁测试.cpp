#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<string> v1;//empty
	{
		vector<string> v2={"hello","world"};
		v1=v2;
	}
	//cout << v2.size();
	cout << v1.size()<<endl;//v2出了作用域就被销毁/v2的元素也被消耗。还可以说明v1和v2的元素是相互分离的。
	 
	return 0;
}

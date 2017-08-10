#include <iostream>
#include <sstream>
using namespace std;

istream& func(istream& is)
{
	int vi = 0;
	auto old_state = is.rdstate();//保存is流的原始状态 
	
	while (is >> vi){
		cout << vi << endl;
	}
	
	is.setstate(old_state);
	//或者直接用is.clear();//这是个重载函数，不接受参数的版本清除（复位）所有错误标志； 
	return is;
}

istream& func1(istream &is){
	string str;
	while (is >> str){
		cout << str << endl;
	}
	is.clear();
	return is;
}

int main(){
	//func(cin);
	string str = "hello world";
	istringstream iss(str);
	func1(iss);
	return 0;
} 

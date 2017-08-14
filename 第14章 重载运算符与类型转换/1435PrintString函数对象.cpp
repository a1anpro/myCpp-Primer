#include <iostream>
using namespace std;
#include <vector>
struct PrintString{
	PrintString(istream &is = cin):_is(is){}
	string operator()(){
		string str;
		getline(_is, str); 
		return _is?str:string();//更优雅的写法 
	}
private:
	istream &_is;
};

int main(){
//	PrintString ps;
//	cout << ps() <<endl;

	vector<string> vec;
	
	PrintString ps;
	string str;
	while ((str = ps()) != ""){
		vec.push_back(str);
	}	
	for (const auto &s:vec){
		cout << s << endl;
	}
	return 0;
} 

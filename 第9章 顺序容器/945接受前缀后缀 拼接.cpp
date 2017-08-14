#include <iostream>
using namespace std;

string func(const string &str, const string& prefix, const string &suffix)
{
	string rstr=prefix;
	
	rstr.insert(rstr.end(),str.begin(), str.end());//用迭代器和insert插入 
	rstr.append(suffix);
	
	return rstr;
}

int main(){
	cout << func("yanhui", "Mrs.", "Jr.")<<endl;
	return 0;
}

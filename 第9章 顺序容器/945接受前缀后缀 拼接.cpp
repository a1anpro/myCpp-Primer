#include <iostream>
using namespace std;

string func(const string &str, const string& prefix, const string &suffix)
{
	string rstr=prefix;
	
	rstr.insert(rstr.end(),str.begin(), str.end());//�õ�������insert���� 
	rstr.append(suffix);
	
	return rstr;
}

int main(){
	cout << func("yanhui", "Mrs.", "Jr.")<<endl;
	return 0;
}

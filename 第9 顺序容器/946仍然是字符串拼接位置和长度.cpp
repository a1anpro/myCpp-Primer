#include <iostream>
using namespace std;

string str_Join(const string &str, const string &prefix, const string &suffix);

int main(){

	cout << str_Join("yanhui", "Mrs.", "Jr.")<<endl;
	
	return 0;
}

inline string str_Join(const string &str, const string &prefix, const string &suffix)
{
	auto rstr = prefix;
	rstr.insert(rstr.size(), str);
	rstr.insert(rstr.size(), suffix);
	
	return rstr;
}


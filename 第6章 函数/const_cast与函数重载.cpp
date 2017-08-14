#include <iostream>
using namespace std;

const string &shortstring(const string &str1, const string &str2){
	return str1.size()<str2.size()?str1 : str2;
}

string &shortstring(string &str1, string &str2){
	auto &r = shortstring(const_cast<const string&>(str1),
							const_cast<const string&>(str2));
	return const_cast<string&>(r);
}

int main(){
	string str1 = "hello";
	string str2 = "sss";
	
	cout << shortstring(str1,str2);
	
	return 0;
}

#include <iostream>
#include <new>
using namespace std;

int main(){
	string str1 = "hello";
	string str2 = "world";
	char *pchr = new char[str1.size() + str2.size()];
	size_t ix = 0;
	for (const auto &s:str1) pchr[ix++]=s;
	for (const auto &s:str2) pchr[ix++]=s;
	
	for (auto t=0; t!=ix; ++t){
		cout << pchr[t] <<"";
	}
	return 0;
}

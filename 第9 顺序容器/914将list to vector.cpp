#include <iostream>
using namespace std;
#include <vector>
#include <list>
int main(){
	list<char*> lpc={"hello","world"};
	vector<string> vstr(lpc.cbegin(), lpc.cend());
	for (const auto &s : vstr){
		cout << s<<endl;
	}
	cout << vstr.max_size()<<endl;
	return 0;
}

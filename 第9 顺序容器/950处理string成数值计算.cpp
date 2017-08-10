#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<string> vstr={"1","2","3"};
	int sum = 0;
	for (const auto &i:vstr){
		sum += stoi(i);//默认是十进制 
	}
	cout << sum<<endl;
	return 0;
}

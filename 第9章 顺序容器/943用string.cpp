#include <iostream>
using namespace std;

void func(string &str, const string &oldVal, const string &newVal)
{
	for (auto beg=str.begin(); distance(beg, str.end()) >= distance(oldVal.begin(), oldVal.end()); )
	{
		if (string{beg, beg+oldVal.size()} == oldVal)
		{
			//ÕÒµ½×Ó´®
			beg = str.erase(beg, beg+oldVal.size());
			//beg = str.insert(beg, newVal.begin(), newVal.end());
			advance(beg, newVal.size()); 
		}
		{
			beg++;
		}
	}
}

void func1(string &str, const string &oldVal, const string &newVal)
{
	for (string::size_type i = 0; i != str.size(); ++i){
		if (str.substr(i, oldVal.size())==oldVal){
			str.replace(i, oldVal.size(), newVal);
			i += newVal.size() - 1;
		}
	}
}


int main(){
	string str = "abcdefghthohhhhh";
	string oldVal = "tho", newVal = "though";
	//func(str,oldVal, newVal);
	func1(str,oldVal, newVal);
	cout << str<<endl;
	return 0;
}

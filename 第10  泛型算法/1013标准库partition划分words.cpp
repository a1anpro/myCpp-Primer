#include <iostream>
#include <algorithm>
using namespace std;
#include <fstream>
#include <vector>
bool isLonger(const string &s)
{
	return s.size() > 3;
}

int main(){
	ifstream ifs("story.txt");
	vector<string> vstr;
	string temp;
	
	while (ifs>>temp){
		vstr.push_back(temp);
	}
	
	auto end_pos = partition(vstr.begin(), vstr.end(), isLonger);
	for (auto ix = vstr.begin(); ix != end_pos; ++ix){
		cout << *ix<< " ";
	}
	return 0;
}

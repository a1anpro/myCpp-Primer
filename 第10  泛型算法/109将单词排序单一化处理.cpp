#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &vstr)
{
	//先排序
	sort(vstr.begin(), vstr.end());
	//再独立化
	auto end_unique = unique(vstr.begin(), vstr.end());
	vstr.erase(end_unique, vstr.end());
}

int main(){
	string filename = "story.txt";
	ifstream  ifs(filename);
	vector<string> vstr;
	if (ifs)
	{
		string words;
		while (ifs>>words)
		{
			vstr.push_back(words);//将单词全部放入vector 
		}
		elimDups(vstr);//重排后，消除重复元素
		stable_sort(vstr.begin(), vstr.end(), isShorter); 
		for (auto i:vstr){
			cout << i <<" ";
		}
	}
		
	return 0;
}

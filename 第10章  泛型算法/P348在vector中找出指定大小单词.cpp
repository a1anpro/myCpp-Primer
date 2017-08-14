#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

void elimDups(vector<string> &vstr)
{
	//将序列中的单词排序并且消除重复
	sort(vstr.begin(), vstr.end());
	auto end_dups = unique(vstr.begin(), vstr.end());
	vstr.erase(end_dups, vstr.end()); 
}

void biggies(vector<string> &words, vector<string>::size_type size)
{
	//找出比指定大小大的单词
	//已经得到了安字典序排好的没有重复的序列
	elimDups(words);
	//现在来得到按长度排序，长度相同的按字典序
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});//第三个参数接受一个谓词。
	
	auto sat_pos = find_if(words.begin(), words.end(), [size](const string &s){return s.size()>=size;});//得到在序列中满足指定长度的第一个迭代器.
	for (auto ix = sat_pos; ix!=words.end(); ++ix){
		cout << *ix << " ";
	} 
}

int main(){
	ifstream ifs("story.txt");
	vector<string> v;
	string temp;
	while (ifs>>temp){
		v.push_back(temp);
	}
	biggies(v, 4);
	
	return 0;
}

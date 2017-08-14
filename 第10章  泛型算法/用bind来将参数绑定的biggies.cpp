#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
void elimDups(vector<string> &vstr)
{
	sort(vstr.begin(), vstr.end());
	auto end_dup = unique(vstr.begin(), vstr.end());
	vstr.erase(end_dup, vstr.end());
}

bool checksize(const string &str, string::size_type size)
{
	return str.size() >= size;
}

void biggies(vector<string> &vstr, vector<string>::size_type size)
{
	elimDups(vstr);//得到了按字典排序的，不重复序列
	//将序列变成长度排序的， 长度一样的按照字典序
	stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2){
		return s1.size() < s2.size(); 
	});
	auto iter = find_if(vstr.begin(), vstr.end(), bind(checksize,placeholders::_1,size));//用_1代替了checksize的第一个参数，也就是传给bind的参数替代checksize的第一个参数
	//用来暂时占位而已。最后一个参数是从checksize中拷贝给bind的；如果要用引用的话，用库函数ref();
	for (auto ix=iter; ix!=vstr.end(); ++ix) cout << *ix << " "; 
}

int main(){
	ifstream istrm("story.txt");
	vector<string> vstr;
	string temp;
	if (istrm)
	{
		while (istrm>>temp)
		{
			vstr.push_back(temp);
		}
		biggies(vstr, 4);
	}
	
	return 0;
}

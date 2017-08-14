#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <fstream>

void elimDups(vector<string> &vstr)
{
	sort(vstr.begin(), vstr.end());
	auto end_dup = unique(vstr.begin(), vstr.end());
	vstr.erase(end_dup, vstr.end());
}

bool check_size(const string &str, string::size_type size){
	return str.size() < size;
}

void biggies(vector<string> &vstr, vector<string>::size_type size)
{
	elimDups(vstr);//得到了按字典排序的，不重复序列
	//将序列变成长度排序的， 长度一样的按照字典序
	stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2){
		return s1.size() < s2.size(); 
	});
//	auto big_iter = partition(vstr.begin(), vstr.end(), [size](const string &str){
//		return size>str.size();
//	});
	
	auto big_iter = partition(vstr.begin(), vstr.end(), bind(check_size, placeholders::_1, size));//用bind来绑定参数 
	
	for (auto ix = big_iter; ix!=vstr.end(); ++ix)
	{
		cout << *ix << " ";
	}
}

//1020中 用count_if计算有多少个元素符合条件
void count(const vector<string> &vstr)
{
	auto cnt = count_if(vstr.begin(), vstr.end(), [](const string &s)->bool{
		if (s.size()>=4) return true;
		else return false;
	});
	cout << "长度超过4的有:"<< cnt<<endl;
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
		count(vstr);
		biggies(vstr, 3);
	}
	
	return 0;
}

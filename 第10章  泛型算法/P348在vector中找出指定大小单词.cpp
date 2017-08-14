#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

void elimDups(vector<string> &vstr)
{
	//�������еĵ��������������ظ�
	sort(vstr.begin(), vstr.end());
	auto end_dups = unique(vstr.begin(), vstr.end());
	vstr.erase(end_dups, vstr.end()); 
}

void biggies(vector<string> &words, vector<string>::size_type size)
{
	//�ҳ���ָ����С��ĵ���
	//�Ѿ��õ��˰��ֵ����źõ�û���ظ�������
	elimDups(words);
	//�������õ����������򣬳�����ͬ�İ��ֵ���
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});//��������������һ��ν�ʡ�
	
	auto sat_pos = find_if(words.begin(), words.end(), [size](const string &s){return s.size()>=size;});//�õ�������������ָ�����ȵĵ�һ��������.
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

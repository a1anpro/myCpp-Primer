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
	elimDups(vstr);//�õ��˰��ֵ�����ģ����ظ�����
	//�����б�ɳ�������ģ� ����һ���İ����ֵ���
	stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2){
		return s1.size() < s2.size(); 
	});
//	auto big_iter = partition(vstr.begin(), vstr.end(), [size](const string &str){
//		return size>str.size();
//	});
	
	auto big_iter = partition(vstr.begin(), vstr.end(), bind(check_size, placeholders::_1, size));//��bind���󶨲��� 
	
	for (auto ix = big_iter; ix!=vstr.end(); ++ix)
	{
		cout << *ix << " ";
	}
}

//1020�� ��count_if�����ж��ٸ�Ԫ�ط�������
void count(const vector<string> &vstr)
{
	auto cnt = count_if(vstr.begin(), vstr.end(), [](const string &s)->bool{
		if (s.size()>=4) return true;
		else return false;
	});
	cout << "���ȳ���4����:"<< cnt<<endl;
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

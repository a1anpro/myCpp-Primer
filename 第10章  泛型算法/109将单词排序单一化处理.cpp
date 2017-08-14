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
	//������
	sort(vstr.begin(), vstr.end());
	//�ٶ�����
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
			vstr.push_back(words);//������ȫ������vector 
		}
		elimDups(vstr);//���ź������ظ�Ԫ��
		stable_sort(vstr.begin(), vstr.end(), isShorter); 
		for (auto i:vstr){
			cout << i <<" ";
		}
	}
		
	return 0;
}

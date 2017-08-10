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
	elimDups(vstr);//�õ��˰��ֵ�����ģ����ظ�����
	//�����б�ɳ�������ģ� ����һ���İ����ֵ���
	stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2){
		return s1.size() < s2.size(); 
	});
	auto iter = find_if(vstr.begin(), vstr.end(), bind(checksize,placeholders::_1,size));//��_1������checksize�ĵ�һ��������Ҳ���Ǵ���bind�Ĳ������checksize�ĵ�һ������
	//������ʱռλ���ѡ����һ�������Ǵ�checksize�п�����bind�ģ����Ҫ�����õĻ����ÿ⺯��ref();
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

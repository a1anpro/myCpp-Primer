#include <iostream>
#include <forward_list>
using namespace std;

void func(forward_list<string> &fli, const string& str1, const string &str2)
{
	//�Ȳ����ٲ���,����ҵ��ͽ�str2���ں��棬δ�ҵ��Ͳ���β��
	auto beg = fli.begin();
	auto prev = fli.before_begin();//����һ���� 
	bool find = false;
	while (beg != fli.end() && !find)
	{
		if (*beg==str1){
			//fli.insert_after(beg,str2);//����
			fli.emplace_after(beg, str2);//���ַ�ʽ��һ���ġ�emplace�İ汾���죬û��������������ֱ���½��� 
			find = true;//�ҵ��˾��˳� 
		}
		else
		{
			//û���ҵ��ͼ���������
			++beg; 
		}
		++prev;
	} 
	//�ж��Ƿ��ҵ����ҵ��˾�ֱ���˳���û�ҵ��Ͳ嵽β��
	if (!find)
	{
		fli.insert_after(prev,str2);//���û���ҵ�������prev����ľ������һ��Ԫ�صĵ�����������ֱ�Ӳ嵽���
		//���û��prev��������޷������� 
	} 
}

int main(){
	forward_list<string> fli={"hello","yanhui","zhuxinyi"};
	string str1 = "yanhui";
	string str2 = "ajiao";
	
	func(fli,str1,str2);
	
	for (const auto &s : fli){
		cout << s<<endl;
	}
	
	return 0;
}

#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <forward_list>
int main(){
	forward_list<int> fli = {1,2,3,4,5,6,7};
	//����������ɾ��ż��
	//Ҫ�������Ҫ�õ���ǰԪ�ص���ǰ������
	auto prev = fli.before_begin();
	auto beg = fli.begin();
	while (beg != fli.end())
	{
		if (*beg % 2)
		{
			beg = fli.insert_after(prev, *beg);//�����Ҫ����beg����begָ��ǰ����Ԫ�صĵ�������
			++beg;++beg;//�ƶ���û�з��ʵ�Ԫ�� 
			++prev;++prev;//�����ú���advance(iter,2); 
		}
		else
		{
			beg = fli.erase_after(prev);
		}
	}
	
	for (const auto &i : fli)
	{
		cout << i << " ";
	}
	
	return 0;
}

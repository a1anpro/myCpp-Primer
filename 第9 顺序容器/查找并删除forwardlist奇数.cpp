#include <iostream>
#include <forward_list>
using namespace std;

int main(){
	forward_list<int> fli{1,2,3,4,5,6,7,8};
	//ɾ������Ԫ��
	auto prev = fli.before_begin();//�õ���ǰ������
	auto curr = fli.begin();//�õ�fli�ĵ�һ��Ԫ�صĵ�����
	
	while (curr!=fli.end())
	{
		if (*curr & 0x1){
			//������ɾ��,����ǰԪ�ص�����
			curr = fli.erase_after(prev);//��ǰ���������䣬curr�ƶ���ɾ�����Ԫ�� 
		}
		else{
			prev = curr;//���浱ǰλ�ã�curr��ǰ�ƶ�
			curr++; 
		}
	} 
	for (const auto &i:fli){
		cout << i<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <forward_list>
int main(){
	list<int> vi = {1,2,3,4,5,6,7};
	//����������ɾ��ż��
	auto iter = vi.begin();//Ҫ�ı�vi
	
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			//�������������뵽��ǰԪ�ص�ǰ��
			iter = vi.insert(iter, *iter);//�����ʹ��ǰ�ĵ�����ʧЧ�����Բ�������֮��Ҫ���µ����� 
			//iter += 2;//�������ٸ��º�ָ��ǰԪ�ء�Ҫ����δ���ʵ�Ԫ����Ҫ�����������λ 
			advance(iter,2);
		}
		else
		{
			//ɾ��ż��
			iter = vi.erase(iter);//ɾ����ָ��iter�����ص���ɾ�����һ��Ԫ�صĵ������� 
		}
	} 
	
	for (const auto &i : vi)
	{
		cout << i << " ";
	}
	
	return 0;
}

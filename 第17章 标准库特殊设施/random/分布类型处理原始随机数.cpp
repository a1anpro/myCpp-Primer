#include <iostream>
using namespace std;
#include <random>
int main(){
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);//��Ϊe���ɵ�������ǲ���ֱ���õ�ԭʼ�������
	//�÷ֲ����Ϳ���ֱ�ӵõ�һ��ָ����Χ�ڵ�����
	
	for (size_t i = 0; i < 10; ++i){
		cout << u(e) <<endl;
	} 
	
	return 0;
}

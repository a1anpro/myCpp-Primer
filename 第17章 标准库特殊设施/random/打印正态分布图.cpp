#include <iostream>
#include <random>
#include <ctime>
using namespace std;
#include <vector>
#include <cmath>
int main(){
	default_random_engine e;
	normal_distribution<> u(4, 1.5);//��ֵΪ4�� ��׼��Ϊ1.5
	vector<unsigned> vals(9);
	
	for (size_t i = 0; i != 100; ++i){
		unsigned v = lround(u(e));//���뵽��ӽ�������
		if (v < vals.size()){
			++vals[v];
		} 
	}
	
	for (size_t i = 0; i != vals.size(); ++i){
		cout << i << ":" << string(vals[i], '*') <<endl;
	}
	return 0;
}

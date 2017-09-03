#include <iostream>
using namespace std;
#include <random>
int main(){
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);//因为e生成的随机数是不能直接用的原始随机数。
	//用分布类型可以直接得到一个指定范围内的数据
	
	for (size_t i = 0; i < 10; ++i){
		cout << u(e) <<endl;
	} 
	
	return 0;
}

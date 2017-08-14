#include <iostream>
#include <memory> 
using namespace std;

int main(){
	allocator<string> alloc;
	size_t n = 10;
	auto p = alloc.allocate(n);//����һ��ԭʼ�ġ�δ������ڴ�
	auto q = p;
	
	string str;
	while (cin >> str){
		alloc.construct(p, str);
		++p;
	}
	 
	while (q!=p){
		cout << *q<<endl;
		alloc.destroy(q++); 
	}
	//alloc.deallocate(p, n);
	 
	return 0;
}

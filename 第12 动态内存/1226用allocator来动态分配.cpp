#include <iostream>
#include <memory> 
using namespace std;

int main(){
	allocator<string> alloc;
	size_t n = 10;
	auto p = alloc.allocate(n);//分配一段原始的、未构造的内存
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

#include <iostream>
#include  <memory>
using namespace std;

int main(){
	allocator<string> alloc;
	auto beg = alloc.allocate(10);
	auto it = beg;
	string str = "hello";//lvalue
	
	alloc.construct(beg, move(str));//调用默认的
	
	alloc.destroy(it);
	alloc.deallocate(it, 10); 
	
	return 0;
}

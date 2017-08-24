#include <iostream>
#include "Shared_Pointer.h"
#include "Unique_Pointer.h"
using namespace std;
#include <memory>

struct MyDelete{
	template<typename T>
	void operator()(T *t){
		cout <<"myDelete" <<endl;
		delete t;
	}
};

int main(){
	Unique_Pointer<int, MyDelete> up(new int(1), MyDelete());//不用传可调用对象:之前的原因是：编写函数的时候在成员里初始化了，应该放在构造里
	//才能跟unique_ptr同步 
	//unique_ptr<int, MyDelete<int>> up(new int(1), MyDelete<int>());
	return 0;
}

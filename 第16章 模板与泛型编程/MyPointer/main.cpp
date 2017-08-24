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
	Unique_Pointer<int, MyDelete> up(new int(1), MyDelete());//���ô��ɵ��ö���:֮ǰ��ԭ���ǣ���д������ʱ���ڳ�Ա���ʼ���ˣ�Ӧ�÷��ڹ�����
	//���ܸ�unique_ptrͬ�� 
	//unique_ptr<int, MyDelete<int>> up(new int(1), MyDelete<int>());
	return 0;
}

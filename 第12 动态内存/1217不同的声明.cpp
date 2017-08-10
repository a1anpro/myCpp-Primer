#include <iostream>
#include <memory>
using namespace std;

int main(){
	int ix=1024, *pi=&ix;
	int *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	
	//IntP p0(ix);//int cannot to pointer..
	//IntP p1(pi);//this can compile,but will cause error at runtime
	//the reason is when unique_ptr p1 is out of scope,delete will be called
	//to free the object.but the object is not allocated using new.
	//thus, an error would be thrown by os;
	
	
	//IntP p2(pi2);//it can compile,but cause a dangling pointer at runtime
	//the reason is that the unique_ptr will free the object the raw pointer is pointing to;
	
	//IntP p3(&ix);//delete to free the object not allocated using new;
	
	IntP p4(new int(2048));//recommended;
	IntP p5(p2.get());//double free or corruption
	
	return 0;
}

#include <iostream>
using namespace std;

struct Delete{
    template<typename T>
    void operator()(T *t){
        delete t;
        t = nullptr;
        cout << "caller"<<endl;
    }
};

template<typename T>
struct Deleter{
    void operator()(T *t){
        delete t;
        t = nullptr;
        cout << "caller"<<endl;
    }
};
    
int main(){
	int *a = new int(10);
//
//	Delete d;
//	d(a);
	
	Deleter<int> d;
	d(a);
	
	if (!a)
		delete a;
	return 0;
}

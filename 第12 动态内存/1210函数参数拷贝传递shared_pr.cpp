#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> p){
	cout << "process shared_ptr num:" << p.use_count()<<endl;
}

int main(){
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p));
	
	cout << "when process() over, shared_ptr num:" << p.use_count()<<endl;
	auto q = p;
	cout << "new num : " << q.use_count()<<endl;
	cout << *q<<endl; 
	
	return 0;
}

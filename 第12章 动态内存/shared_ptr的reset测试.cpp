#include <iostream>
#include <memory>
using namespace std;

int main(){
	shared_ptr<int> p(new int(42));
	auto q(p);
	cout << p.use_count() << " " << q.use_count() <<endl;
	
	p.reset(new int(12));
	cout << p.use_count() << " " << q.use_count() <<endl;
	
	return 0;
}

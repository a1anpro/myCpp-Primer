#include <iostream>
#include <memory>

using namespace std;

int main(){
	shared_ptr<int> spt = make_shared<int>(42);
	shared_ptr<string> spts = make_shared<string>(10,'8');
	if (spt && spts){
		cout<<*spt<<endl;
		cout << *spts<<endl;
	}
	
	return 0;
}

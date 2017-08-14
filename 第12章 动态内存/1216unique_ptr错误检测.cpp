#include <iostream>
#include <memory>
using namespace std;

int main(){
	unique_ptr<int> up(new int(10));
	//unique_ptr<int> up2(up);
	
	cout << *up<<endl;
	
	up.reset(nullptr);
	return 0;
} 

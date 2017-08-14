#include <iostream>
using namespace std;

struct absInt{
	int operator()(int val)const{
		return val<0?-val:val;
	}
};

int main(){
	
	absInt obj;
	int ret = obj(-10);
	cout << ret;
	
	return 0;
} 

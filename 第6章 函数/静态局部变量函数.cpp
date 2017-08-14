#include <iostream>
using namespace std;

size_t func(){
	static size_t cnt = 0;
	return cnt++;
}

int main(){
	for (int i = 0; i < 10; ++i){
		cout << func()<<endl;
	}
	
	return 0;
} 

#include <iostream>
#include "StrVec.h" 
using namespace std;

int main(){
	StrVec vec({"hello","world"});
	
	cout << vec.size()<<endl;
	
	for (auto beg = vec.begin(); beg != vec.end(); ++beg){
		cout << *beg<<endl;
	}
		
	return 0;
}

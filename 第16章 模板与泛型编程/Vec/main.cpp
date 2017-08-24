#include <iostream>
using namespace std;
#include "Vec.h"

int main(){
	Vec<string> vs;
	string str = "hello";
	vs.emplace_back(str);
	cout << vs[0]<<endl;
	cout << vs.size()<<endl;
	
	return 0;
}

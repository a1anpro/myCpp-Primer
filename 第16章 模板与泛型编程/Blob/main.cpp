#include <iostream>
using namespace std;
#include "BlobPtr.h"

int main(){
	vector<int> v{1,2,3};
	
	Blob<int> b(v.begin(), v.end());//函数可以根据传入的参数来推断类型 
		
	return 0;
}

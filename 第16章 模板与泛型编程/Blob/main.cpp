#include <iostream>
using namespace std;
#include "BlobPtr.h"

int main(){
	vector<int> v{1,2,3};
	
	Blob<int> b(v.begin(), v.end());//�������Ը��ݴ���Ĳ������ƶ����� 
		
	return 0;
}

#include <iostream>
#include <unordered_map>//���������Ǵ���������� 

using namespace std;

int main(){
	unordered_map<string,string> um;
	
	um["yanhui"] = "hello";
	um["alone"] = "world";
	size_t pos = 0;
	cout << um.bucket_count()<<endl;
	cout << um.max_bucket_count() <<endl;
	cout << um.bucket_size(0)<<endl;
	pos = um.bucket("yanhui");
	cout <<  pos<<endl;
	cout << um.bucket_size(pos)<<endl;
	
	return 0;
}

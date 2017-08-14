#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int ia[10]={1,2,3,4,5,6,7,8,9,0};
	int ia2[sizeof(ia)/sizeof(*ia)];
	
	copy(begin(ia),end(ia), ia2);
	for (auto i:ia2) cout << i <<endl;
	
	return 0;
}

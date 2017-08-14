#include <iostream>
using namespace std;
#include <vector>
void print(vector<int> v, int inx){
	if (inx == v.size()) return ;
	cout << v[inx]<<endl;
	print(v,inx+1);
}

int main(){
	vector<int> v{1,2,3,4,5};
	print(v,0);
	
	return 0;
} 

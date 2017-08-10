#include <iostream>
#include <array>
using namespace std;

int main(){
	array<int,3> a = {1,2,3};
	
	for (auto i : a){
		cout << i << " ";
	}
	a = {4,5,6};
	for(auto i:a)cout << i<<endl;

	return 0;
}

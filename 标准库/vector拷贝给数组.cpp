#include <iostream>
using namespace std;
#include <vector>
int main(){
	vector<int> a{1,2,3,4,5,6,7};
	int arr[a.size()];
	
	for (auto i = 0; i < a.size(); ++i){
		arr[i] = a[i];
	}
	
	for (auto i : arr){
		cout << i << endl;
	}
	return 0;
} 

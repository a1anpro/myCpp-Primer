#include <iostream>
using namespace std;
#include <vector>

int main(){
	const vector<int> cv{1,2,3,4,5};
	for (int i = 1; i != 10; ++i){
		//cv.push_back(i);
	}	
	//cv[0] = 2;//每个元素都是const 
	for (auto i : cv){
		cout << i<<endl;
	}
	for (auto it = cv.cbegin(); it != cv.cend(); ++it){
		cout << *it  <<endl;
	}
	return 0;
} 

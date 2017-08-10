#include <iostream>
using namespace std;
#include <vector>
int main(){
	constexpr size_t array_size = 10;
	unsigned ia[array_size];
	for (size_t i = 0; i != array_size; ++i){
		ia[i] = i;
	}
	for (auto t : ia){
		cout << t <<endl;
	}
	
	vector<int> vi(10);
	for (auto it = vi.begin(); it != vi.end(); ++it){
		*it = it-vi.begin();
	}
	vector<int> vi2(vi);
	
	for (auto t:vi){
		cout << t <<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	int ia[3][4]={0};
	size_t cnt = 0;
	
	for (auto &row:ia){
		for (auto &col : row){
			col = cnt;
			cnt++;
		}
	}
	
	for (const auto &row : ia){
		for (auto col : row){
			cout << col << endl;
		}
	}
	return 0;
}

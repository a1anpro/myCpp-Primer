#include <iostream>
using namespace std;
#include <iterator>
#include <vector>
#include <algorithm>

int main(){
	vector<int> vi;
	vector<int> vi2(10);
	
	fill_n(back_inserter(vi), 10 ,0);
	
	for (auto i:vi) cout << i <<endl;
	cout << "--------"<<endl;
	fill(vi2.begin(), vi2.begin()+4, 5);
	for (auto i:vi2)cout << i<<endl;
	return 0;
}

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(){
	istream_iterator<int> in_iter(cin), eof;
	vector<int> vi(in_iter, eof);
	
	for (auto i:vi)cout << i<<" ";
	
	return 0;
}

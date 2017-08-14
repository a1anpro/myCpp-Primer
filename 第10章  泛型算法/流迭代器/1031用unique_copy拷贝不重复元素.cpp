#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <iterator>


int main(){
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vi(in_iter, eof);
	vector<int> uni_vi;
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), back_inserter(uni_vi));
	copy(uni_vi.begin(), uni_vi.end(), out_iter);
	
	return 0;
}

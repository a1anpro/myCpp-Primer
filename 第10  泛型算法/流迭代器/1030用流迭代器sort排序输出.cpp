#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <iterator>

int main(){
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vi(in_iter, eof);//用范围迭代器 初始化
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), out_iter);
	
	return 0;
}

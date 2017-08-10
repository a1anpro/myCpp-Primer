#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	istream_iterator<int> in_iter(cin),eof;
	cout << accumulate(in_iter, eof, 0)<<endl;
	return 0;
}

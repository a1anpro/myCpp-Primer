#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream ifs("text.txt");
	ostream_iterator<string> out_iter(cout, " ");
	istream_iterator<string> if_iter(ifs), eof;
	
	vector<string> vstr(if_iter, eof);
	
	//for (auto s:vstr) out_iter=s;
	copy(vstr.begin(), vstr.end(), out_iter);
	return 0;
}

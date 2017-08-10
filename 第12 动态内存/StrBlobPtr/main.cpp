#include <iostream>
#include "StrBlobPtr.h"
using namespace std;
#include <fstream>
#include <sstream>

int main(){
	ifstream istrm("words.txt");
	string line;
	StrBlob sb;
	
	while (istrm >> line){
		sb.push_back(line);
	}
		
	for (StrBlobPtr pbeg(sb.begin()), pend(sb.end()); pbeg!=pend; pbeg.incr()){
		cout << pbeg.deref()<<endl;
	}
	
	return 0;
}

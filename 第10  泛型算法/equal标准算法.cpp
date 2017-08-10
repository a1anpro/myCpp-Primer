#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(){
//	char c1[10]="helo";
//	char c2[10]="helo";
//	vector<char*> v1{c1};
//	vector<char*> v2{c2};
//	cout << equal(v1.cbegin(), v1.cend(), v2.cbegin();
	
	vector<string> vs1 = {"hello","world"};
	vector<string> vc = {"hello"};
	
	cout << equal(vs1.cbegin(), vs1.cend(), vc.cbegin())<<endl;
	
	return 0;
}

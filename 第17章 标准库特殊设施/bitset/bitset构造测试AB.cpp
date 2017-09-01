#include <iostream>
#include <bitset>
using namespace std;

int main(){
	string bacon = "ABABB";
	bitset<5> bv(bacon, 0, string::npos, 'A', 'B');
	
	cout << bv << endl;	
	return 0;
} 

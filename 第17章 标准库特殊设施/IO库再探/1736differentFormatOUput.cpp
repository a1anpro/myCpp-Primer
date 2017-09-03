#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i = 10;
	double d = 3.1415926535;
	
	cout << setw(20) << d <<endl;
	cout << setw(20) << i <<endl;
	cout << left << setw(20) << d<<endl;
	cout << left << setw(20) << i<<endl << right;
	
	cout << setfill('$') << setw(20) << d<<endl;
	cout << setfill(' ');
	return 0;
}

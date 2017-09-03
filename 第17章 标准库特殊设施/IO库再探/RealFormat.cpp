#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	const double PI = 3.1415926535;
//	cout.precision(3);
//	cout << cout.precision()<<endl;
//	cout << PI <<endl;
//	
	
	cout << sqrt(2.0) <<endl;
	
	cout << setprecision(12);
	cout << cout.precision() << ' ' << sqrt(2.0) <<endl;
	
	cout << showpos;
	//cout << scientific;
	cout << fixed;
	
	cout << 100000.0 <<endl;
	
	return 0;
}

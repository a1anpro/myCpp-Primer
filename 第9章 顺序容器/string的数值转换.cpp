#include <iostream>
using namespace std;

int main(){
	double d = 1.423;
	string str = to_string(d);
	cout <<str<<endl;
	d = stod(str);
	cout <<d<<endl;
	return 0;
}

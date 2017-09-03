#include <iostream>
using namespace std;

int main(){
	
	cout << showbase << uppercase;//showbase manipulator output the format of system: hex with 0x, octonary with 0
	
	cout << hex << 10 <<endl;
	cout << 20 <<endl;//output the hex format of 20 until the manipulator changed;	
	
	cout << nouppercase << noshowbase << dec;//use these to reset the ostream;
	
	return 0;
}

#include <iostream>
using namespace std;
#include "screen.h"

int main(){
	Screen myScreen(5,5,'x');
	myScreen.move(4,0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);	
	return 0;
}

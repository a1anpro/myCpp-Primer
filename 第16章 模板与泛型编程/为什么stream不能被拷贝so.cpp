#include <iostream>
using namespace std;
#include <sstream>

int main(){
	
	istringstream iss("hello");
	istringstream iss2(iss.str());
	
	return 0;
}

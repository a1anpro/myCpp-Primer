#include <iostream>
#include <new>
#include <cstring>
#include <string>
using namespace std;

int main(){
	const char *c1 = "hello";
	const char *c2 = "world";
	unsigned len = strlen(c1) + strlen(c2);
	char *r = new char[len]();

	strcat(r, c1);
	strcat(r, c2);
	
	cout << r<<endl;
	
	return 0;
}

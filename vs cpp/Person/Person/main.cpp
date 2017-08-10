#include <iostream>
#include "Person.h"

using namespace std;

int main() {
	//Person("yanhui", "yichang");
	Person p(cin);

	print(cout, p);

	return 0;
}
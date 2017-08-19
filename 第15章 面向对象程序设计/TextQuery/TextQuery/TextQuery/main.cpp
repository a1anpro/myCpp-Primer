#include <iostream>
#include <fstream>

#include "Derived.h"
using namespace std;

int main() {
	ifstream ifs("text.txt");
	TextQuery tq(ifs);

	Query q("you");
	//q.eval(tq);

	return 0;
}
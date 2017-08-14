#include <iostream>
using namespace std;
#include "TextQuery.h"

int main(){
	ifstream infile("text.txt");
	runQueries(infile);
	return 0;
}

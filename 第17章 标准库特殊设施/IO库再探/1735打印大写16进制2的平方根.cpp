#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>
int main()
{
	cout <<"default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexidecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << '\n' 
		<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
		<< "\n\n";
}

//i do not know why hexfloat and defaultflaot not in this scope

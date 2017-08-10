#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

ostream& print(ostream &os, const Person &p) {
	os << p.getName() << " " << p.getAddress();
	return os;
}
istream& read(istream &is, Person &p) {
	is >> p.name >> p.address;//
	return is;
}
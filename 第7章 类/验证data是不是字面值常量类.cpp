#include <iostream>
using namespace std;

class Data{
public:
	int ival;
	string s;	
};

int main()
{
	cout << boolalpha<<endl;
	cout << is_literal_type<Data>::value<<endl;
	return 0;
}

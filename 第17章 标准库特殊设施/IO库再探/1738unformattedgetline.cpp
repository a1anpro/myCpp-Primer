#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	constexpr int n = 100; 
	ifstream myfile("text.txt");
	if (myfile) cout << 1 <<endl;
	
	char sink[n];
	size_t cnt = 0;

	while(myfile.getline(sink, n))
  	{
  		++cnt;
    	cout << sink << endl;
	}
	
	cout << cnt <<endl;
	return 0;
}

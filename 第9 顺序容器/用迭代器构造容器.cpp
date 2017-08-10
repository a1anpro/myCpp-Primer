#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
	list<int> li={1,2,3,4};
	vector<double> vd(li.begin(), li.end());
	
	for (const auto &t : vd){
		cout << t<<endl;
	}
	return 0;
}

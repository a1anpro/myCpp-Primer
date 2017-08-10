#include <iostream>
using namespace std;

int main(){
	int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//≥ı ºªØ	
	
	for (const auto &cow : ia){
		for (auto col : cow){
			cout << col << " ";
		}
		cout << endl;
	} 
	
	return 0;
}

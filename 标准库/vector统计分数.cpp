#include <iostream>
using namespace std;
#include <vector>

int main(){
	vector<unsigned> scores(11,0);//11¸öµµ´Î
	
	unsigned grade = 0;
	while (cin >> grade){
		if (grade<=100){
			++scores[grade/10];
		}
	} 
	
	return 0;
}

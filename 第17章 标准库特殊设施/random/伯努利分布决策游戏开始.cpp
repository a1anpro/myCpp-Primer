#include <iostream>
#include <random>
#include <ctime>
using namespace std;

bool game(bool first){
	return true;
}

int main(){
	default_random_engine e(10);
	bernoulli_distribution b(0.55); //当前给程序一个小小的优势 
	//默认是50/50的机会	
	
	string resp;//如果resp是在循环内定义，则不在while的作用域内。 
	
	do{
		bool first = b(e);//If true, program first
		cout << (first ? "we go first" : "you get to go first")<<endl;
		cout << (game(first) ? "sorry, you lost" : "congrats you won") <<endl;
		cout << "play again? Enter 'yes' or 'no'" << endl; 
	}
	while (cin >> resp && resp == "yes");
	
	return 0;
}

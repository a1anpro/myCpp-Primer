#include <iostream>
#include <random>
#include <ctime>
using namespace std;

bool game(bool first){
	return true;
}

int main(){
	default_random_engine e(10);
	bernoulli_distribution b(0.55); //��ǰ������һ��СС������ 
	//Ĭ����50/50�Ļ���	
	
	string resp;//���resp����ѭ���ڶ��壬����while���������ڡ� 
	
	do{
		bool first = b(e);//If true, program first
		cout << (first ? "we go first" : "you get to go first")<<endl;
		cout << (game(first) ? "sorry, you lost" : "congrats you won") <<endl;
		cout << "play again? Enter 'yes' or 'no'" << endl; 
	}
	while (cin >> resp && resp == "yes");
	
	return 0;
}

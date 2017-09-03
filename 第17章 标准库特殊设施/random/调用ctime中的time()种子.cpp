#include <iostream>
using namespace std;
#include <ctime>
#include <windows.h>
int main(){
	for (size_t i = 0; i < 10; ++i){
		Sleep(500);//Í£¶Ù£¨¹ÒÆð£©500ms 
		cout << time(0) <<endl;
	}
	
	return 0;
}

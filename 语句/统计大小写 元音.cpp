#include <iostream>
using namespace std;
#include <cctype>
int main(){
	int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0;
	string input;
	while (cin >> input){
		for (auto c:input){
			char temp = toupper(c);
			switch (temp){
				case 'A':aCnt++;break;
				case 'E':eCnt++;break;
				case 'I':iCnt++;break;
				case 'O':oCnt++;break;
				case 'U':uCnt++;break;
				default : ;break;
			}
		}
	}
	cout << "a has " << aCnt<<endl;
	cout << "e has " << eCnt<<endl;
	cout << "i has " << iCnt<<endl;
	cout << "o has " << oCnt<<endl;
	cout << "u has " << uCnt<<endl;
	
	return 0;
}

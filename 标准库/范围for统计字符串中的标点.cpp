#include <iostream>
using namespace std;
#include <cctype>
int main(){
	string str = "hello,world!!!";
	decltype(str.size()) punct_cnt = 0;//ͳ�Ƶĸ���Ӧ�ú� size������һ�� 
	
	for (auto c : str){
		if (ispunct(c)){
			++punct_cnt;
		}
	}
	
	cout << punct_cnt << " punctuation characters in "<< str<<endl;
	return 0;
}

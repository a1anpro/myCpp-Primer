#include <iostream>
using namespace std;
#include <cctype>
int main(){
	string s = "hello,world";
	
	for (decltype(s.size()) index = 0; index != s.size() && !ispunct(s[index]); ++index){
		s[index] = toupper(s[index]);
	}
	//&&��������������ã����&&ǰ����Żῴ&&����߼��жϣ�Ҳ����˵ֻ��index�ڷ�Χ�ڣ��Ż���s[index] 
	cout << s<<endl;
	return 0;
} 

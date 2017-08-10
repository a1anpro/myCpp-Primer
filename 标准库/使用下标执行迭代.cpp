#include <iostream>
using namespace std;
#include <cctype>
int main(){
	string s = "hello,world";
	
	for (decltype(s.size()) index = 0; index != s.size() && !ispunct(s[index]); ++index){
		s[index] = toupper(s[index]);
	}
	//&&运算符有屏蔽作用，如果&&前是真才会看&&后的逻辑判断，也就是说只有index在范围内，才会检查s[index] 
	cout << s<<endl;
	return 0;
} 

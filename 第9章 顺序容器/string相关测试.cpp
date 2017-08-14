#include <iostream>
using namespace std;

int main(){
	string s("hello, cpp primer");
	string s2 = s;
	
	s.insert(s.size(), " 5th!");
	s2.append(" 5th!");
	
//	if (s==s2){
//		cout << s<<endl;
//	}
	
	//eraseºÍinsertµÄ¼òÐ´£ºreplace
	s.erase(18,3);
	s.insert(18, "5TH");
	cout << s <<endl;
	
	s2.replace(18,3,"6TH");
	cout << s2<<endl;
	return 0;
}

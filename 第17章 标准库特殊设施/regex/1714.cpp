#include <iostream>
#include <regex>
using namespace std;

int main(){
	try{
//		string pattern("[^c]ei");
//		pattern = "[[:alpha:]]*"+pattern+"[[:alpha:]]*";
//		regex r(pattern, regex::ECMAScript);
		regex r("[[:alpha:]]*(cie|[^c]ie)[[:alpha:]]*", regex::optimize);//为什么不能用regex::ECMAScript 
		
	}
	catch(regex_error e){
		cout << e.what() <<endl;
	}	
	return 0;
}

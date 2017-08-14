#include <iostream>
using namespace std;
#include <map>
#include <vector>

int main(){
	map<string, vector<string>> family;
	string lastName, firstName;
	
	//advanced version:use lambda
	//      ~~
	//i use a implict capture to use lastName.otherwise we can not input into lastName
	while ([&]()->bool{//if lambda has more than one statement, you should use this format to figure out return value
		cout << "please input your lastname:";
		cin >> lastName;
		return lastName!="@q";//@q±Ì æΩ· ¯ 
	}())
	//^^
	//the () used here is to call the lambda, otherwise it doesn't work...cause lambda statement is also a callable statement,so wo can use ();
	{
		cout << "please input your children's  name:";
		while (cin >> firstName && firstName!="@q"){
			family[lastName].push_back(firstName);
		}
	}
	
//	while (cin >> fir_name)
//	{
//		while (cin >> child_name){
//			family[fir_name].push_back(child_name);
//		}
//	}
	
	for (const auto &f:family){
		cout << f.first << " has " << f.second.size() << " children, which includes :";
		for (const auto &t:family[f.first]){
			cout << t<< " ";
		}
	}
		
	return 0;
}

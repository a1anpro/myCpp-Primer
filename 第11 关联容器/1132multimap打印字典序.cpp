#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	multimap<string, string> writer;
	map<string, set<string>> author;	
	
	writer.emplace("yanhui", "hello");
	writer.emplace("yanhui", "hello1");
	writer.emplace("zhoujgasd", "world");	
	writer.emplace("yanhui", "hello2");
		

	for (const auto &w:writer){
		author[w.first].insert(w.second);
	}
	
	for (const auto &a:author){
		cout << a.first << " : ";
		for (const auto &b : a.second){
			cout << b << " ";
		}
		cout << endl;
	}
	
	return 0;
} 

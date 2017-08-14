#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

void count_words(map<string, size_t> &count)
{
	string word;
	while (cin>>word){
		for (auto &i:word) i=tolower(i);
		word.erase(remove_if(word.begin(), word.end(), [](char c){
			return ispunct(c);
		}), word.end());
		++count[word]; 
	}
}

int main(){
	map<string, size_t> count;
	
	count_words(count);
	
	for (const auto &w:count){
		cout << w.first << " occurs " << w.second << "times"<<endl;
	}
	
	return 0;
}

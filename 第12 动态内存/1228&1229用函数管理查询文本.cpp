#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <set>
#include <map>
using namespace std;

void runQueries(ifstream &infile){
	map<string, set<size_t>> wordMap;
	vector<string> text;
	size_t lineNum = 0;
	
	string line;
	while (getline(infile, line)){
		text.push_back(line);
		istringstream iss(line);
		string word;
		while (iss >> word){
			wordMap[word].insert(lineNum);
		}
		++lineNum;
	}
	while (true){
		string s;
		cout << "enter word you want to query, or q to quit:";
		cin >> s;
		if (s=="q") break;
		for (auto beg = wordMap[s].cbegin(); beg != wordMap[s].cend(); ++beg){
			cout << *beg << " : " <<text[*beg] <<endl;
		}
	}
	
}

int main(){
	ifstream infile("text.txt");
	runQueries(infile);
	
	return 0;
}

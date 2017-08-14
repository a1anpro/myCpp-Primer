#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
	//用map来保存单词和行号
	map<string, list<size_t>> word_pos;
	ifstream istrm("text.txt");
	size_t line_num = 1;
	string line;
	while (getline(istrm, line)){
		//把文件中的一行读进line，并且将行号存入单词
		istringstream iss(line);
		string word;
		while (iss >> word){
			word_pos[word].push_back(line_num);//把每个单词出现的位置存入list 
		}
		++line_num;
	} 
	
	for (const auto &w:word_pos){
		cout << w.first << " in: ";
		for (const auto &t:w.second){
			cout << t << " ";
		}
		cout <<endl;
	}
	
	return 0;
}

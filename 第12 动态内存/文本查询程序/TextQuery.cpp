#include "TextQuery.h"

TextQuery::TextQuery(ifstream &infile){
	string line;
	size_t lineNum=0;
	while (getline(infile, line)){
		text.push_back(line);//��ÿһ�д���vector 
		istringstream iss(line);
		string word;
		while (iss >> word){
			wordMap[word].insert(lineNum);//���ʶ�Ӧ��set�в����к� 
		}
		++lineNum;
	}
}

QueryResult TextQuery::query(string word){
		//Ҫ��map���ҵ�word��Ӧ��set��
		QueryResult qs(make_shared<set<size_t>>(wordMap[word]), make_shared<vector<string>>(text));
		return qs;
}

void print(ostream &os, QueryResult qs){
	size_t temp = 0;
	auto beg = qs.result->cbegin();
	auto end = qs.result->cend();
	auto text = qs.text;
	while (beg!=end){
		os << *beg << ":" << (*text)[*beg]<<endl;
		beg++;
	}
}

void runQueries(ifstream &infile){
	TextQuery tq(infile);
	while (true){
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin>>s) || s=="q") break;
		print(cout, tq.query(s));
		cout <<endl;
	}
}

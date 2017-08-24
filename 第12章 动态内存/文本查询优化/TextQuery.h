#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;

class DebugDelete{
public:
	DebugDelete(ostream &s = cerr):os(s){}
	
	template<typename T>
	void operator()(T *d){
		os << "deleteing unique_ptr"<<endl;
		delete d;//
	}
private:
	ostream &os;
};

class QueryResult;
class TextQuery{
public:
	using lineNo = vector<string>::size_type;
	TextQuery()=default;
	TextQuery(ifstream &infile);
	
	QueryResult query(string word) const;//查询得到的是 QueryResult 
private:
	shared_ptr<vector<string>> text;
	map<string, shared_ptr<set<lineNo>>> wordMap;
};

class QueryResult{
public:
	friend ostream &print(ostream&, const QueryResult&); 
	//构造函数 
	QueryResult()=default;
	QueryResult(string sword, shared_ptr<vector<string>> stext, shared_ptr<set<TextQuery::lineNo>> slines):
		sought(sword),text(stext),lines(slines){}
		
private:
	string sought;//查询单词 
	shared_ptr<vector<string>> text;
	shared_ptr<set<TextQuery::lineNo>> lines;
};

void runQueries(ifstream &infile);

#endif

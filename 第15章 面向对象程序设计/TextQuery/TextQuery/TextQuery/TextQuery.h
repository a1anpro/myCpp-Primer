#pragma
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;

class QueryResult;
class TextQuery {
public:
	using lineNo = vector<string>::size_type;
	TextQuery() = default;
	TextQuery(ifstream &infile);

	QueryResult query(string word) const;//查询得到的是 QueryResult 
private:
	shared_ptr<vector<string>> text;//装文本的每一行
	map<string, shared_ptr<set<lineNo>>> wordMap;//每个单词对应一个set
};

class QueryResult {
public:
	friend ostream &print(ostream&, const QueryResult&);
	//构造函数 
	QueryResult() = default;
	QueryResult(string sword, shared_ptr<vector<string>> stext, shared_ptr<set<TextQuery::lineNo>> slines) :
		sought(sword), text(stext), lines(slines) {}
	set<TextQuery::lineNo>::iterator begin() const {
		return lines->begin();//返回指向set的（存在位置）迭代器
	}
	set<TextQuery::lineNo>::iterator end() const {
		return lines->end();
	}
	shared_ptr<vector<string>> get_files() const {
		return text;
	}
private:
	string sought;//查询单词 
	shared_ptr<vector<string>> text;//指向文本的指针
	shared_ptr<set<TextQuery::lineNo>> lines;//指向set的指针
};

void runQueries(ifstream &infile);

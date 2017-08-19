#include "TextQuery.h"

TextQuery::TextQuery(ifstream &infile) :text(new vector<string>)//构造的时候动态新建内存 
{
	string line;
	lineNo lineNum = 0;
	while (getline(infile, line)) {
		text->push_back(line);
		istringstream iss(line);
		string word;
		while (iss >> word) {
			auto &lines = wordMap[word];//得到shared_ptr的引用
			if (!lines) {
				lines.reset(new set<lineNo>);//分配一个新的set 
			}
			lines->insert(lineNum);
		}
		lineNum++;//行号增加 
	}
}

QueryResult TextQuery::query(string word)const {
	//先在map中查是否存在这个单词，如果不存在的话应该返回空的set 
	static shared_ptr<set<TextQuery::lineNo>> nodata(new set<TextQuery::lineNo>);

	//用find函数来查询，避免向map中插入新的
	auto loc = wordMap.find(word);
	if (loc == wordMap.cend()) {
		return QueryResult(word, text, nodata);
	}
	else {
		return QueryResult(word, text, loc->second);
	}
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << "occurs " << qr.lines->size() << " times :" << endl;

	for (auto pos : (*qr.lines)) {
		os << "line " << pos + 1 << ":" << (*qr.text)[pos] << endl;
	}
	return os;
}

void runQueries(ifstream &infile) {
	TextQuery tq(infile);

	while (true) {
		cout << "enter word to look for, q to quit:";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}
}
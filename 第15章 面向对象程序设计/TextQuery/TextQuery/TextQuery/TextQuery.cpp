#include "TextQuery.h"

TextQuery::TextQuery(ifstream &infile) :text(new vector<string>)//�����ʱ��̬�½��ڴ� 
{
	string line;
	lineNo lineNum = 0;
	while (getline(infile, line)) {
		text->push_back(line);
		istringstream iss(line);
		string word;
		while (iss >> word) {
			auto &lines = wordMap[word];//�õ�shared_ptr������
			if (!lines) {
				lines.reset(new set<lineNo>);//����һ���µ�set 
			}
			lines->insert(lineNum);
		}
		lineNum++;//�к����� 
	}
}

QueryResult TextQuery::query(string word)const {
	//����map�в��Ƿ����������ʣ���������ڵĻ�Ӧ�÷��ؿյ�set 
	static shared_ptr<set<TextQuery::lineNo>> nodata(new set<TextQuery::lineNo>);

	//��find��������ѯ��������map�в����µ�
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
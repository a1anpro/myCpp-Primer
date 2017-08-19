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

	QueryResult query(string word) const;//��ѯ�õ����� QueryResult 
private:
	shared_ptr<vector<string>> text;//װ�ı���ÿһ��
	map<string, shared_ptr<set<lineNo>>> wordMap;//ÿ�����ʶ�Ӧһ��set
};

class QueryResult {
public:
	friend ostream &print(ostream&, const QueryResult&);
	//���캯�� 
	QueryResult() = default;
	QueryResult(string sword, shared_ptr<vector<string>> stext, shared_ptr<set<TextQuery::lineNo>> slines) :
		sought(sword), text(stext), lines(slines) {}
	set<TextQuery::lineNo>::iterator begin() const {
		return lines->begin();//����ָ��set�ģ�����λ�ã�������
	}
	set<TextQuery::lineNo>::iterator end() const {
		return lines->end();
	}
	shared_ptr<vector<string>> get_files() const {
		return text;
	}
private:
	string sought;//��ѯ���� 
	shared_ptr<vector<string>> text;//ָ���ı���ָ��
	shared_ptr<set<TextQuery::lineNo>> lines;//ָ��set��ָ��
};

void runQueries(ifstream &infile);

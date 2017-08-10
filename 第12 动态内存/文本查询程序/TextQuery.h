#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <set>
#include <map>
using namespace std;

class QueryResult;
class TextQuery{
public:	
	TextQuery()=default;//Ĭ�Ϲ��캯��
	TextQuery(ifstream &infile);
	
	QueryResult query(string word);
private:
	//���ı���vector
	vector<string> text;
	//�浥�ʵ�map
	map<string,set<size_t>> wordMap; 
};

class QueryResult{
public:
	QueryResult()=default;
	QueryResult(shared_ptr<set<size_t>> it, shared_ptr<vector<string>> tstr):result(it), text(tstr){}
	
//private:
	//���shared_ptr��ָ�����Ҫ���ʵĲ�ѯ�����set
	shared_ptr<set<size_t>> result; 
	shared_ptr<vector<string>> text;
};

void print(ostream &os, QueryResult qs);
void runQueries(ifstream &infile);
#endif

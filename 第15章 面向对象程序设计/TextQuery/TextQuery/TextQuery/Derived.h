#pragma once
#include "Query_base.h"

//ʵ��Query_base�������࣬ʵ�������Ĳ�ѯ
//�������еĲ�ѯ��������������ʵ�ʲ������Ǳ���װ���صģ�ֻ��ͨ��Query��ӿڲ��ܱ���ӷ���
class WordQuery :public Query_base{
	friend class Query;//��Query���Žӿ�
private:
	WordQuery(const string &s):query_word(s){}

	//������ࣺWordQuery���������м̳ж����Ĵ��麯��
	QueryResult eval(const TextQuery &t) const {
		return t.query(query_word);//
	}
	string rep() const {
		return query_word;//
	}
	string query_word;//Ҫ��ѯ�Ĵ�
};

//~���������һ��NotQuery�����б�����һ����Ҫ����ȡ����Query
class NotQuery :public Query_base {
	friend Query operator~(const Query &);
private:
	NotQuery(const Query &q):query(q){}

	QueryResult eval(const TextQuery &t) const;
	string rep() const {
		return string() + "~(" + query.rep() + ")";
	}

	//������ࣺWordQuery���������м̳ж����Ĵ��麯��
	Query query;
};

//Ҳ��һ���������
class BinaryQuery :public Query_base{
protected:
	BinaryQuery(const Query &l, const Query &r, const string &s):
		lhs(l), rhs(r), opSym(s){}

	//�����࣬BinaryQuery������eval
	string rep() const {
		return "(" + lhs.rep() + " "
			+ opSym + " "
			+ rhs.rep() +  ")";
	}

	Query lhs, rhs;//�����Ҳ��������
	string opSym;//�����������
};

class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query &);
private:
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}
	//������࣬�̳���rep���Ҷ����������麯��
	QueryResult eval(const TextQuery &) const;
};

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query &);
private:
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}
	//������࣬�̳���rep���Ҷ����������麯��
	QueryResult eval(const TextQuery &) const;
};


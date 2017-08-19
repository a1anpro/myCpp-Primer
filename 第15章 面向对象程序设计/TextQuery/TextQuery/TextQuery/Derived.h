#pragma once
#include "Query_base.h"

//实现Query_base的派生类，实现真正的查询
//我们所有的查询：基类和派生类的实际操作都是被封装隐藏的，只有通过Query类接口才能被外接访问
class WordQuery :public Query_base{
	friend class Query;//给Query开放接口
private:
	WordQuery(const string &s):query_word(s){}

	//具体的类：WordQuery将覆盖所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const {
		return t.query(query_word);//
	}
	string rep() const {
		return query_word;//
	}
	string query_word;//要查询的词
};

//~运算符生成一个NotQuery，其中保存着一个需要对其取反的Query
class NotQuery :public Query_base {
	friend Query operator~(const Query &);
private:
	NotQuery(const Query &q):query(q){}

	QueryResult eval(const TextQuery &t) const;
	string rep() const {
		return string() + "~(" + query.rep() + ")";
	}

	//具体的类：WordQuery将覆盖所有继承而来的纯虚函数
	Query query;
};

//也是一个抽象基类
class BinaryQuery :public Query_base{
protected:
	BinaryQuery(const Query &l, const Query &r, const string &s):
		lhs(l), rhs(r), opSym(s){}

	//抽象类，BinaryQuery不定义eval
	string rep() const {
		return "(" + lhs.rep() + " "
			+ opSym + " "
			+ rhs.rep() +  ")";
	}

	Query lhs, rhs;//左侧和右侧运算对象
	string opSym;//运算符的名字
};

class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query &);
private:
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}
	//具体的类，继承了rep并且定义其他的虚函数
	QueryResult eval(const TextQuery &) const;
};

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query &);
private:
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}
	//具体的类，继承了rep并且定义其他的虚函数
	QueryResult eval(const TextQuery &) const;
};


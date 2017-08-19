#pragma once

#include "TextQuery.h"

class Query;

class Query_base {
	//派生类和用户都不能直接使用Query_base，所以要把友元类给Query
	friend class Query;
protected:
	using line_no = TextQuery::lineNo;
	virtual ~Query_base() = default;//要隐式的在派生类的析构函数中使用，就最低要求是受保护的

private:
	//返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;//虚函数
														 //rep表示查询的是一个string
	virtual string rep() const = 0;
};


//Query对外提供接口，同时隐藏了Query_base的继承体系
class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const string &);//构建一个新的WordQuery

						  //接口函数：调用对应的Query_base
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	string rep() const {
		return q->rep();
	}
private:
	Query(shared_ptr<Query_base> query) :q(query) {}//一个只能内部使用的构造函数，用Query_base构造的指针
	shared_ptr<Query_base> q;//指向Query_base的智能指针
};



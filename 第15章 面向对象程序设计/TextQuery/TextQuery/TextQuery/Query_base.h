#pragma once

#include "TextQuery.h"

class Query;

class Query_base {
	//��������û�������ֱ��ʹ��Query_base������Ҫ����Ԫ���Query
	friend class Query;
protected:
	using line_no = TextQuery::lineNo;
	virtual ~Query_base() = default;//Ҫ��ʽ���������������������ʹ�ã������Ҫ�����ܱ�����

private:
	//�����뵱ǰQueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;//�麯��
														 //rep��ʾ��ѯ����һ��string
	virtual string rep() const = 0;
};


//Query�����ṩ�ӿڣ�ͬʱ������Query_base�ļ̳���ϵ
class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const string &);//����һ���µ�WordQuery

						  //�ӿں��������ö�Ӧ��Query_base
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	string rep() const {
		return q->rep();
	}
private:
	Query(shared_ptr<Query_base> query) :q(query) {}//һ��ֻ���ڲ�ʹ�õĹ��캯������Query_base�����ָ��
	shared_ptr<Query_base> q;//ָ��Query_base������ָ��
};



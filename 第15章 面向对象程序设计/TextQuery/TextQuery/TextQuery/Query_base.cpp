#include "Query_base.h"
#include "Derived.h"
ostream& operator<<(ostream &os, const Query &query) {
	//Query::repͨ������Query_baseָ���rep()�����������
	return os << query.rep();
}

inline Query::Query(const string &s) :q(new WordQuery(s)) {}
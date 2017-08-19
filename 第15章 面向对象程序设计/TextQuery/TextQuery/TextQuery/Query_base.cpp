#include "Query_base.h"
#include "Derived.h"
ostream& operator<<(ostream &os, const Query &query) {
	//Query::rep通过它的Query_base指针对rep()进行了虚调用
	return os << query.rep();
}

inline Query::Query(const string &s) :q(new WordQuery(s)) {}
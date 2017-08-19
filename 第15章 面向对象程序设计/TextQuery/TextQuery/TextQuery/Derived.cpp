#include "Derived.h"
#include <algorithm>
#include <iterator>
using namespace std;
inline Query operator~(const Query &operand) {
	return shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text)const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = make_shared<set<TextQuery::lineNo>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());

	return QueryResult(rep(), left.get_files(), ret_lines);
}

QueryResult AndQuery::eval(const TextQuery &text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);//�õ���QueryResult
	auto ret_lines = make_shared<set<TextQuery::lineNo>>();//�յ�
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), right.get_files(), ret_lines);
}

QueryResult NotQuery::eval(const TextQuery &text) const {
	//��text���в�ѯ
	auto result = query.eval(text);//��ѯ�õ�QueryResult,,�õ����֡�set���ı���ÿһ��
	auto ret_lines = make_shared<set<TextQuery::lineNo>>();//�õ��յ�setָ�룬�����淵�ؽ��
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_files()->size();//�õ��ı�������
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n) {
			ret_lines->insert(n);//�������result���У��������һ��
		}
		else if (beg != end) {
			++beg;//
		}
	}
	return QueryResult(rep(), result.get_files(), ret_lines);
}

#include "Disc_quote.h"
#include <set>
#include <memory>
using namespace std;

class Basket{
public:
	void add_item(const Quote &sale);
	void add_item(Quote &&sale);
	
	//��ӡÿ������ܼۺ͹���������������ܼۡ� 
	double total_receipt(ostream &) const;
	
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs){
		return lhs->isbn() < rhs->isbn();//�Զ���ıȽ�shared_ptr�ĺ��� 
	}
	
	multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};//Ϊʲô�û����ţ� 
};

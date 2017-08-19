#include "Disc_quote.h"
#include <set>
#include <memory>
using namespace std;

class Basket{
public:
	void add_item(const Quote &sale);
	void add_item(Quote &&sale);
	
	//打印每本书的总价和购物篮中所有书的总价。 
	double total_receipt(ostream &) const;
	
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs){
		return lhs->isbn() < rhs->isbn();//自定义的比较shared_ptr的函数 
	}
	
	multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};//为什么用花括号？ 
};

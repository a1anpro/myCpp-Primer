#include "quote.h"

double print_total(ostream &os, Quote const &item, size_t n){
	double ret = item.net_price(n);//返回的是买n本书要的价钱 
	os << "ISBN:" << item.isbn() <<"# sold:" << n << " total due:" << ret<<endl;
	return ret;
}



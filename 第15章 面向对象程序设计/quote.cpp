#include "quote.h"

double print_total(ostream &os, Quote const &item, size_t n){
	double ret = item.net_price(n);//���ص�����n����Ҫ�ļ�Ǯ 
	os << "ISBN:" << item.isbn() <<"# sold:" << n << " total due:" << ret<<endl;
	return ret;
}



#include "Disc_quote.h"

double Bulk_quote::net_price(size_t n) const {
		if (n >= min_qty){
			return price * (1-discount) * n;
		}
		else{
			return price * n;
		}
}

double Limit_quote::net_price(size_t n) const {
		if (n < min_qty){
			return n * price;
		}
		else if (n < max_qty){
			//��������Ǵ��۵�
			return n * price * (1 - discount); 
		}
		else{//����������䣬ʣ��Ĳ����� 
			return max_qty * price * (1 - discount) + (n - max_qty) * price;
		}
}

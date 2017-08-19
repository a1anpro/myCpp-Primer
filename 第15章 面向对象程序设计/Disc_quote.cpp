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
			//这个区间是打折的
			return n * price * (1 - discount); 
		}
		else{//超过这个区间，剩余的不打折 
			return max_qty * price * (1 - discount) + (n - max_qty) * price;
		}
}

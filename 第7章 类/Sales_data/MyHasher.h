#include "Sales_data.h"

namespace std{
	template<>//我们正在定义一个特例化版本，模板参数是Sales_data
	struct hash<Sales_data>{
		typedef size_t result_type;
		typedef Sales_data arguement_type;//默认情况下，需要==的重载
		size_t operator()(const Sales_data &s) const; 
	}; 
	
	size_t hash<Sales_data>::operator()(const Sales_data &s)const
	{
		return hash<string>()(s.bookNo) ^
		       hash<unsigned>()(s.units_sold)^
		       hash<double>()(s.revenue);
	}
}

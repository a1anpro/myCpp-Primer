#include "Sales_data.h"

namespace std{
	template<>//�������ڶ���һ���������汾��ģ�������Sales_data
	struct hash<Sales_data>{
		typedef size_t result_type;
		typedef Sales_data arguement_type;//Ĭ������£���Ҫ==������
		size_t operator()(const Sales_data &s) const; 
	}; 
	
	size_t hash<Sales_data>::operator()(const Sales_data &s)const
	{
		return hash<string>()(s.bookNo) ^
		       hash<unsigned>()(s.units_sold)^
		       hash<double>()(s.revenue);
	}
}

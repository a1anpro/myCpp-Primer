#include "Sales_data.h"

Sales_data::Sales_data( istream& is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
   Sales_data ret = lhs;
   ret += rhs;
   return ret;
}

 istream& operator>>( istream& is, Sales_data& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)//check if input is successful 
        item.revenue = price * item.units_sold;
    else//input error:item is assigned for default value
        item = Sales_data();
    return is;
}

 ostream& operator<<( ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
       << item.avg_price();
    return os;//书的isbn、销量、销售收入、均值 
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	if (lhs.bookNo == rhs.bookNo){
		return true;
	}
	return false;
}
bool operator<(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo < rhs.bookNo;
}



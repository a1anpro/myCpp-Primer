#include <iostream>
using namespace std;
#include "Sales_data.h"

//���캯��
Sales_data::Sales_data(istream &is){
	read(is, *this);//
} 

//�ǳ�Ա����
ostream& print(ostream &os, const Sales_data &item) {
	//�ô��������� ����
	os << item.isbn() << " "<< item.units_sold <<" "
		<<item.revenue << " " << item.avg_price();
	return os; 
}
istream& read(istream &is, Sales_data &item){
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold*price;
	return is;
}

 
//���Ա���� 
Sales_data& Sales_data::add(const Sales_data &item){
	if (bookNo != item.bookNo){
		return *this;
	}
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}
Sales_data& Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

void Sales_data::CalcRevenue(double price){
	revenue = units_sold * price;//������*���� 
}
void Sales_data::SetData(Sales_data data){
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
}

void  Sales_data::AddData(Sales_data data){
	if (bookNo != data.bookNo){
		return ;
	}
	units_sold += data.units_sold;
	revenue += data.revenue;
}

#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
using namespace std;

class Quote{
public:
	Quote()=default;
	Quote(const string &book, double sales_price):bookNo(book),price(sales_price){}
	//拷贝控制成员和移动拷贝成员
	//拷贝构造函数
	Quote(const Quote &rhs):price(rhs.price), bookNo(rhs.bookNo){
		cout << "Quote Copy Constructor" << endl;
	}
	//拷贝赋值函数
	Quote& operator=(const Quote &rhs){
		cout << "Quote Copy assignment operator" << endl;
        price = rhs.price;
        bookNo = rhs.bookNo;
        return *this;
	}
	//移动构造函数
	Quote(Quote &&rhs)noexcept:price(move(rhs.price)), bookNo(move(rhs.bookNo)){
		 cout << "Quote Move Constructor" << endl;
	}
	//移动赋值函数
	Quote& operator=(Quote &&rhs)noexcept{
		cout << "Quote Move assignment operator" << endl;
		price = move(rhs.price);
		bookNo = move(rhs.bookNo);
		return *this;
	}
	//该虚函数返回当前对象的一份动态分配的拷贝
	virtual Quote* clone() const & {return new Quote(*this);}
	virtual Quote* clone() && {return new Quote(move(*this));}
	 
	string isbn() const {return bookNo;}
	
	virtual double net_price(size_t n)const{
		return n * price;
	}
	virtual ~Quote()//基类都应该定义析构函数，即使它什么都不做
	{
		cout << "Quote Destructor" << endl;
	} 
protected:
	double price = 0.0;

private:
	string bookNo;	
};



double print_total(ostream &os, Quote const &item, size_t n);

#endif

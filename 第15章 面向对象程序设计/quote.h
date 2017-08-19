#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
using namespace std;

class Quote{
public:
	Quote()=default;
	Quote(const string &book, double sales_price):bookNo(book),price(sales_price){}
	//�������Ƴ�Ա���ƶ�������Ա
	//�������캯��
	Quote(const Quote &rhs):price(rhs.price), bookNo(rhs.bookNo){
		cout << "Quote Copy Constructor" << endl;
	}
	//������ֵ����
	Quote& operator=(const Quote &rhs){
		cout << "Quote Copy assignment operator" << endl;
        price = rhs.price;
        bookNo = rhs.bookNo;
        return *this;
	}
	//�ƶ����캯��
	Quote(Quote &&rhs)noexcept:price(move(rhs.price)), bookNo(move(rhs.bookNo)){
		 cout << "Quote Move Constructor" << endl;
	}
	//�ƶ���ֵ����
	Quote& operator=(Quote &&rhs)noexcept{
		cout << "Quote Move assignment operator" << endl;
		price = move(rhs.price);
		bookNo = move(rhs.bookNo);
		return *this;
	}
	//���麯�����ص�ǰ�����һ�ݶ�̬����Ŀ���
	virtual Quote* clone() const & {return new Quote(*this);}
	virtual Quote* clone() && {return new Quote(move(*this));}
	 
	string isbn() const {return bookNo;}
	
	virtual double net_price(size_t n)const{
		return n * price;
	}
	virtual ~Quote()//���඼Ӧ�ö���������������ʹ��ʲô������
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

#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"

class Disc_quote:public Quote{//�������麯��������ǳ������ 
public:
	Disc_quote()=default;
	Disc_quote(const string &book, double price, size_t minq, double dis):
		Quote(book, price),min_qty(minq), discount(dis){}

	//�������Ƴ�Ա���ƶ�������Ա
	//�������캯��
	Disc_quote(const Disc_quote &dq):Quote(dq){
		cout << "Disc_quote Copy Constructor" << endl;
	}
	//������ֵ����
	Disc_quote& operator=(const Disc_quote &rhs){
		cout << "Disc_quote Copy assignment operator" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}
	//�ƶ����캯��
	Disc_quote(Disc_quote &&rhs)noexcept:Quote(move(rhs)), min_qty(move(rhs.min_qty)), discount(move(rhs.discount))//��ʽ�Ľ���ֵת������ֵ 
	{
		cout << "Disc_quote Move constructor" << endl;
	}
	//�ƶ���ֵ����
	Disc_quote& operator=(Disc_quote &&rhs) noexcept
	{
		cout << "Disc_quote Move assignment operator" << endl;
		Quote::operator=(move(rhs));
		min_qty = move(rhs.min_qty);
		discount = move(rhs.discount);
		return *this;
	}
	//��������
	~Disc_quote(){
		
		cout << "Disc_quote destructor" <<endl;
	} 
	
	double net_price(size_t n) const  = 0;//���麯�� 
	
protected://Ҫ������������ʹ��˽�г�Ա������Ҫ����Ϊprotected�������� 
	size_t min_qty = 0;
	double discount = 0.0;
};

class Bulk_quote:public Disc_quote{
public:
	Bulk_quote()=default;
	Bulk_quote(const string &book, double price, size_t minq, double discount):
		Disc_quote(book,price,minq, discount){}
//	using Disc_quote::Disc_quote;//�̳�Disc_quote�Ĺ��캯��,����ΪʲôҪ�̳� ���캯�� 
	 
	//�������캯����
	Bulk_quote(const Bulk_quote &rhs):Disc_quote(rhs){
		cout << "Bulk_quote copy constructor "<<endl;
	}
	//������ֵ�������
	Bulk_quote& operator=(const Bulk_quote &rhs){
		cout << "Bulk_quote copy assignment"<<endl;
		Disc_quote::operator=(rhs);
		return *this;
	} 
	//�ƶ����캯��
	Bulk_quote(Bulk_quote &&rhs)noexcept:Disc_quote(move(rhs)){
		cout << "Bulk_quote move constructor "<<endl;
	}
	Bulk_quote& operator=(Bulk_quote &&rhs)noexcept{
		cout << "Bulk_quote move assignment "<<endl;
		Disc_quote::operator=(move(rhs));
		return *this;
	}
	~Bulk_quote(){
		cout << "Bulk_quote destructor" <<endl;
	}
	
	//�����麯�� 
	virtual Bulk_quote* clone() const & {return new Bulk_quote(*this);}
	virtual Bulk_quote* clone() && {return new Bulk_quote(move(*this));}
	
	double net_price(size_t) const override;//��ʽ�����Ǹ��Ǻ��� 
};

class Limit_quote:public Disc_quote{
public: 
	Limit_quote()=default;
	Limit_quote(const string &book, double price, size_t minq, double discount):
		Disc_quote(book,price,minq, discount){}
	double net_price(size_t) const override;//��ʽ�����Ǹ��Ǻ��� 

private:
	//�����Լ���˽�г�Ա
	size_t max_qty = 0;//�ﵽ������Ͳ�������
};

#endif

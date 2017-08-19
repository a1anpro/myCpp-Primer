#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include "quote.h"

class Disc_quote:public Quote{//包含纯虚函数的类就是抽象基类 
public:
	Disc_quote()=default;
	Disc_quote(const string &book, double price, size_t minq, double dis):
		Quote(book, price),min_qty(minq), discount(dis){}

	//拷贝控制成员和移动拷贝成员
	//拷贝构造函数
	Disc_quote(const Disc_quote &dq):Quote(dq){
		cout << "Disc_quote Copy Constructor" << endl;
	}
	//拷贝赋值函数
	Disc_quote& operator=(const Disc_quote &rhs){
		cout << "Disc_quote Copy assignment operator" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}
	//移动构造函数
	Disc_quote(Disc_quote &&rhs)noexcept:Quote(move(rhs)), min_qty(move(rhs.min_qty)), discount(move(rhs.discount))//显式的将左值转换成右值 
	{
		cout << "Disc_quote Move constructor" << endl;
	}
	//移动赋值函数
	Disc_quote& operator=(Disc_quote &&rhs) noexcept
	{
		cout << "Disc_quote Move assignment operator" << endl;
		Quote::operator=(move(rhs));
		min_qty = move(rhs.min_qty);
		discount = move(rhs.discount);
		return *this;
	}
	//析构函数
	~Disc_quote(){
		
		cout << "Disc_quote destructor" <<endl;
	} 
	
	double net_price(size_t n) const  = 0;//纯虚函数 
	
protected://要让它的派生类使用私有成员，必须要声明为protected访问限制 
	size_t min_qty = 0;
	double discount = 0.0;
};

class Bulk_quote:public Disc_quote{
public:
	Bulk_quote()=default;
	Bulk_quote(const string &book, double price, size_t minq, double discount):
		Disc_quote(book,price,minq, discount){}
//	using Disc_quote::Disc_quote;//继承Disc_quote的构造函数,不懂为什么要继承 构造函数 
	 
	//拷贝构造函数：
	Bulk_quote(const Bulk_quote &rhs):Disc_quote(rhs){
		cout << "Bulk_quote copy constructor "<<endl;
	}
	//拷贝赋值运算符：
	Bulk_quote& operator=(const Bulk_quote &rhs){
		cout << "Bulk_quote copy assignment"<<endl;
		Disc_quote::operator=(rhs);
		return *this;
	} 
	//移动构造函数
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
	
	//善用虚函数 
	virtual Bulk_quote* clone() const & {return new Bulk_quote(*this);}
	virtual Bulk_quote* clone() && {return new Bulk_quote(move(*this));}
	
	double net_price(size_t) const override;//显式声明是覆盖函数 
};

class Limit_quote:public Disc_quote{
public: 
	Limit_quote()=default;
	Limit_quote(const string &book, double price, size_t minq, double discount):
		Disc_quote(book,price,minq, discount){}
	double net_price(size_t) const override;//显式声明是覆盖函数 

private:
	//定义自己的私有成员
	size_t max_qty = 0;//达到这个量就不打折了
};

#endif

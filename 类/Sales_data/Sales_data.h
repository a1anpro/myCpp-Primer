#include <iostream>
#include <string>
using namespace std;

struct Sales_data{
	friend ostream& print(ostream &os, const Sales_data &item);
	friend istream& read(istream &is, Sales_data &item);

public:
//构造函数
	Sales_data(const string &s, unsigned n, double p):
				bookNo(s),units_sold(n),revenue(p*n){}//{ cout << "被委托的B构造"<<endl;}
	
//委托构造函数
	//Sales_data():Sales_data(" ",0,0.0){}//{cout << "委托的A构造 -- 默认" <<endl;}
	//Sales_data(istream &is):Sales_data(){}//{cout << "委托的A构造 -- cin"<< endl; read(is, *this);} 

//#原构造函数 
	Sales_data() = default;
	Sales_data(const string &s):bookNo(s){ }
	Sales_data(istream &is);

//成员函数 
	void CalcRevenue(double price);
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	Sales_data &add(const Sales_data &item);
	Sales_data &combine(const Sales_data &rhs);
	
	//返回isbn，加const是为了让常量对象能够调用该函数	
	string isbn() const{
		return bookNo;
	}
	
private:
	inline double avg_price() const;//内联函数的声明和定义写在一起。 
private:
	string bookNo;//书的编号
	unsigned units_sold = 0;//
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const{//如果不用const的话，返回的值是不安全的，在print中不能使用 
	if (units_sold != 0){
		return revenue / units_sold;
	}
	else{
		return 0.0;
	}
}

//类定义相关的非成员函数的声明 应该放在和类声明的同一个文件里 
ostream& print(ostream &os, const Sales_data &item);
istream& read(istream &is, Sales_data &item);


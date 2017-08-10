#include <iostream>
#include <string>
using namespace std;

struct Sales_data{
	friend ostream& print(ostream &os, const Sales_data &item);
	friend istream& read(istream &is, Sales_data &item);

public:
//���캯��
	Sales_data(const string &s, unsigned n, double p):
				bookNo(s),units_sold(n),revenue(p*n){}//{ cout << "��ί�е�B����"<<endl;}
	
//ί�й��캯��
	//Sales_data():Sales_data(" ",0,0.0){}//{cout << "ί�е�A���� -- Ĭ��" <<endl;}
	//Sales_data(istream &is):Sales_data(){}//{cout << "ί�е�A���� -- cin"<< endl; read(is, *this);} 

//#ԭ���캯�� 
	Sales_data() = default;
	Sales_data(const string &s):bookNo(s){ }
	Sales_data(istream &is);

//��Ա���� 
	void CalcRevenue(double price);
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	Sales_data &add(const Sales_data &item);
	Sales_data &combine(const Sales_data &rhs);
	
	//����isbn����const��Ϊ���ó��������ܹ����øú���	
	string isbn() const{
		return bookNo;
	}
	
private:
	inline double avg_price() const;//���������������Ͷ���д��һ�� 
private:
	string bookNo;//��ı��
	unsigned units_sold = 0;//
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const{//�������const�Ļ������ص�ֵ�ǲ���ȫ�ģ���print�в���ʹ�� 
	if (units_sold != 0){
		return revenue / units_sold;
	}
	else{
		return 0.0;
	}
}

//�ඨ����صķǳ�Ա���������� Ӧ�÷��ں���������ͬһ���ļ��� 
ostream& print(ostream &os, const Sales_data &item);
istream& read(istream &is, Sales_data &item);


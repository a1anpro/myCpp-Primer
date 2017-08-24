#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
using namespace std;

// added overloaded input, output, addition, and compound-assignment operators
class Sales_data {
    friend  istream& operator>>( istream&, Sales_data&);       // input
    friend  ostream& operator<<( ostream&, const Sales_data&); // output
    friend Sales_data operator+(const Sales_data&,
                                const Sales_data&); // addition

public:
    Sales_data(const  string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p)
    {
    }
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const  string& s) : Sales_data(s, 0, 0.0f) {}
    Sales_data( istream& is);

    Sales_data& operator+=(const Sales_data&); // compound-assignment
     string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;//revenue means income
};

istream& operator>>( istream&, Sales_data&);
ostream& operator<<( ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

template<typename T>
int compare(const T &lhs, const T &rhs){
	if (less<T>()(lhs, rhs)) return 1;
	else if (less<T>()(rhs, lhs)) return -1;
	else return 0;
}

#endif

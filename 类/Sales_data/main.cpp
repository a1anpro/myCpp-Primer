#include <iostream>
using namespace std;
#include "Sales_data.h"
#include <vector>
#include <fstream>
#include <sstream>//string的流 
#include <algorithm>
#include <iterator>
#include <set>

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
	return s1.isbn() < s2.isbn();
}

int main(){
	//构造Sales_data的set 
	//set<Sales_data, bool (*)(const Sales_data&,const Sales_data&)> bookstore(compareIsbn);
	//set<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	//set<Sales_data, auto ()->bool (*)(const Sales_data&, const Sales_data&)> store(compareIsbn);
	
	return 0;
}
//	vector<Sales_data> vs;
//	ifstream ifs("record.txt");
//	
//	if (ifs)
//	{
//		string temp;
//		while (getline(ifs, temp))
//		{
//			istringstream iss(temp);
//			Sales_data sd(iss);
//			vs.push_back(sd);
//		}
//		
//		sort(vs.begin(), vs.end(), compareIsbn);
//		for (const auto s:vs)
//		{
//			print(cout, s);
//			cout << endl;
//		}
//	}	
//	
//	Sales_data total(cin);
//	if (!total.isbn().empty()){
//		istream &is = cin;//cin的引用
//		while (is){
//			Sales_data trans(is);
//			if (total.isbn() == trans.isbn()){
//				total.add(trans);
//			}
//			else{
//				//如果是同一本书的话 就加一起，不是的话就输出并丢弃 
//				print(cout, total) <<endl;
//				total = trans;//把当前书 换成 新的 
//			}
//		} 
//	}
//	else{
//		cerr << "No data" <<endl;
//		return -1;	
//	}
	
//	const Sales_data sd1;
//	cout << sd1.isbn()<<endl;
//	
//	Sales_data total;
//	if (cin >> total.bookNo >> total.units_sold >> total.revenue){
//		Sales_data trans;
//		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
//			if (total.bookNo == trans.bookNo){
//				total.AddData(trans);
//			}
//			else{
//				total.Print();
//				total = trans;
//			}
//		}
//		total.Print();
//	}
//	else{
//		cerr << "no data?!" <<endl;
//		return -1;
//	}

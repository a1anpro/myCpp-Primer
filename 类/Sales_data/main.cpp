#include <iostream>
using namespace std;
#include "Sales_data.h"
#include <vector>
#include <fstream>
#include <sstream>//string���� 
#include <algorithm>
#include <iterator>
#include <set>

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
	return s1.isbn() < s2.isbn();
}

int main(){
	//����Sales_data��set 
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
//		istream &is = cin;//cin������
//		while (is){
//			Sales_data trans(is);
//			if (total.isbn() == trans.isbn()){
//				total.add(trans);
//			}
//			else{
//				//�����ͬһ����Ļ� �ͼ�һ�𣬲��ǵĻ������������ 
//				print(cout, total) <<endl;
//				total = trans;//�ѵ�ǰ�� ���� �µ� 
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

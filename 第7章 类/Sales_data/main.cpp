#include <iostream>
using namespace std;
#include "Sales_data.h"
#include "MyHasher.h"
#include <vector>
#include <fstream>
#include <sstream>//string���� 
#include <algorithm>
#include <iterator>
#include <set>
#include <unordered_set>

//���еĲ����������ŵ����ļ��� 
#include "testFunction.h"

//��Ҫ������꣺
vector<Sales_data> buildStore(const string &store){
	//�������������������ж�ȡ���� ����vector 
	vector<Sales_data> ret;

	ifstream ifs(store);
	if (ifs)
	{
		//cout << "�ļ���";
		Sales_data sd;
		while (ifs >> sd) ret.push_back(sd);
	}
	else{
		//cout << "û�д��ļ�"<<endl;
	}
	
	sort(ret.begin(), ret.end(), 
		[](const Sales_data &lhs, const Sales_data &rhs){
			return lhs < rhs;
		});//��lambda���ʽ���Ƚ� 
	
	return ret;
} 

int main(){
	vector<vector<Sales_data>> files;
	
	for (size_t i = 1; i <= 3; ++i){
		files.push_back(buildStore("SalesData/" + to_string(i) + ".txt"));
	}
	//���½��ĵ��ڵ� ���ۼ�¼��Ҫ�������򣬷�������Ч��equal_range
	reportResults(cin, cout, files);
	
	return 0;
}
////	Sales_data a, b;
////	compare(a,b);
//
//	Sales_data s1("123", 12, 12), s2("1234", 13, 123);
//	unordered_multiset<Sales_data> ums;
//	
//	ums.insert(s1);
//	ums.insert(s2);
//	
////	unordered_multiset<int> s;
//	
//	for (const auto &item : ums){
//		cout << item.isbn()<<endl;
//	}


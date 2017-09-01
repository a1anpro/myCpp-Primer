#include <iostream>
using namespace std;
#include "Sales_data.h"
#include "MyHasher.h"
#include <vector>
#include <fstream>
#include <sstream>//string的流 
#include <algorithm>
#include <iterator>
#include <set>
#include <unordered_set>

//所有的测试用例都放到该文件夹 
#include "testFunction.h"

//先要构建书店：
vector<Sales_data> buildStore(const string &store){
	//给了书店名，从书店名中读取数据 存入vector 
	vector<Sales_data> ret;

	ifstream ifs(store);
	if (ifs)
	{
		//cout << "文件打开";
		Sales_data sd;
		while (ifs >> sd) ret.push_back(sd);
	}
	else{
		//cout << "没有打开文件"<<endl;
	}
	
	sort(ret.begin(), ret.end(), 
		[](const Sales_data &lhs, const Sales_data &rhs){
			return lhs < rhs;
		});//用lambda表达式来比较 
	
	return ret;
} 

int main(){
	vector<vector<Sales_data>> files;
	
	for (size_t i = 1; i <= 3; ++i){
		files.push_back(buildStore("SalesData/" + to_string(i) + ".txt"));
	}
	//对新建的店内的 销售记录还要进行排序，否则不能有效做equal_range
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


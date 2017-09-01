//17.4测试头文件 
#include <numeric>
#include <tuple>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

//统计多个书店中，某一本书的销售情况;返回的是vector 存的是 tuple<size_t, vector<Sales_data>::iterator,...>
using matchs = tuple<size_t, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;//返回的vector的内容 
vector<matchs> findBook(const string &book, const vector<vector<Sales_data>> &files)
{
	vector<matchs> ret;
	
//	for (auto &item : files){//访问外层vector，内存vector是每个书店的销售记录 
//		 auto range = equal_range(item.cbegin(), item.cend(), book);
//		 if (range.first != range.second){
//		 	ret.push_back(make_tuple())//如果用范围for的话，就不知道下标了 
//		 }
//	}
	
	for (auto iter = files.cbegin(); iter != files.cend(); ++iter){
		auto found = equal_range(iter->cbegin(), iter->cend(), book);
		if (found.first != found.second){
			ret.push_back(make_tuple(iter - files.cbegin(), found.first, found.second));//tuple必须要直接初始化 
		}
	}
	
	return ret; 
}
//使用返回的tuple的vector，查询并打印
void reportResults(istream &is, ostream &os, const vector<vector<Sales_data>> &files)
{
	string book;
	while (is >> book){
		auto result = findBook(book, files);//得到vector
		if (result.empty()){
			os << "this book is not found in any bookstore"<<endl;
			continue;//其实可以不用 
		} 
		else{
			//找到了这本书的所有销售记录
			//输出，在几号店里买了多少钱：
			for (const auto &item: result){
				//vector 中的元素是tuple
				os << "store " << get<0>(item) << " sales " << 
						accumulate(get<1>(item), get<2>(item), Sales_data(book))
															<<endl;//Sales_book定义输出<< 
			} 
		}
	}
} 


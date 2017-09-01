#pragma once
#include "Sales_data.h"
#include <numeric>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

//统计多个书店中，某一本书的销售情况;返回的是vector 存的是 tuple<size_t, vector<Sales_data>::iterator,...>
using matchs = tuple<size_t, 
vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;//返回的vector的内容 
vector<matchs> findBook(const string &book, const vector<vector<Sales_data>> &files);
//使用返回的tuple的vector，查询并打印
void reportResults(istream &is, ostream &os, const vector<vector<Sales_data>> &files);

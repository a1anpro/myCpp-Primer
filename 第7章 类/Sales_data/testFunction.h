#pragma once
#include "Sales_data.h"
#include <numeric>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

//ͳ�ƶ������У�ĳһ������������;���ص���vector ����� tuple<size_t, vector<Sales_data>::iterator,...>
using matchs = tuple<size_t, 
vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;//���ص�vector������ 
vector<matchs> findBook(const string &book, const vector<vector<Sales_data>> &files);
//ʹ�÷��ص�tuple��vector����ѯ����ӡ
void reportResults(istream &is, ostream &os, const vector<vector<Sales_data>> &files);

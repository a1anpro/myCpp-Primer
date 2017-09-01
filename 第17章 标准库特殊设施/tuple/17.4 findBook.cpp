//17.4����ͷ�ļ� 
#include <numeric>
#include <tuple>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

//ͳ�ƶ������У�ĳһ������������;���ص���vector ����� tuple<size_t, vector<Sales_data>::iterator,...>
using matchs = tuple<size_t, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>;//���ص�vector������ 
vector<matchs> findBook(const string &book, const vector<vector<Sales_data>> &files)
{
	vector<matchs> ret;
	
//	for (auto &item : files){//�������vector���ڴ�vector��ÿ���������ۼ�¼ 
//		 auto range = equal_range(item.cbegin(), item.cend(), book);
//		 if (range.first != range.second){
//		 	ret.push_back(make_tuple())//����÷�Χfor�Ļ����Ͳ�֪���±��� 
//		 }
//	}
	
	for (auto iter = files.cbegin(); iter != files.cend(); ++iter){
		auto found = equal_range(iter->cbegin(), iter->cend(), book);
		if (found.first != found.second){
			ret.push_back(make_tuple(iter - files.cbegin(), found.first, found.second));//tuple����Ҫֱ�ӳ�ʼ�� 
		}
	}
	
	return ret; 
}
//ʹ�÷��ص�tuple��vector����ѯ����ӡ
void reportResults(istream &is, ostream &os, const vector<vector<Sales_data>> &files)
{
	string book;
	while (is >> book){
		auto result = findBook(book, files);//�õ�vector
		if (result.empty()){
			os << "this book is not found in any bookstore"<<endl;
			continue;//��ʵ���Բ��� 
		} 
		else{
			//�ҵ����Ȿ����������ۼ�¼
			//������ڼ��ŵ������˶���Ǯ��
			for (const auto &item: result){
				//vector �е�Ԫ����tuple
				os << "store " << get<0>(item) << " sales " << 
						accumulate(get<1>(item), get<2>(item), Sales_data(book))
															<<endl;//Sales_book�������<< 
			} 
		}
	}
} 


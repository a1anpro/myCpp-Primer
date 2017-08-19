#include <iostream>
#include "Disc_quote.h"
#include <vector>
#include <memory>
using namespace std;

void testVector(shared_ptr<Quote> ptr){
	vector<shared_ptr<Quote>> basket;
	
	basket.push_back(ptr);
	
	cout << basket.back()->net_price(10)<<endl;
}

int main(){
	//Bulk_quote bq;
	//Bulk_quote bq1(move(bq));
	
	testVector(make_shared<Quote>(Quote("123",10)));//����ú��������������⣬������Quote��ָ��������ã�make_shared�Ƕ�̬���ͣ� 
	
	return 0;
}

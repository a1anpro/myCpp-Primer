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
	
	testVector(make_shared<Quote>(Quote("123",10)));//如何用函数来解决这个问题，传的是Quote的指针或者引用，make_shared是动态类型？ 
	
	return 0;
}

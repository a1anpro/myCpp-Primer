#include "basket.h"

double Basket::total_receipt(ostream &os) const{
	//打印每本书的销售情况，并返回总的消费金额
	double sum = 0.0;
	
	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)){
		sum += print_total(os, **iter, items.count(*iter));
	}
	
	os << "Total sales:" << sum << endl;//打印消费总额
	return sum; 
}

//拷贝给定对象 
void Basket::add_item(const Quote &sale){
	items.insert(shared_ptr<Quote>(sale.clone()));
}
//移动给定对象
void Basket::add_item(Quote &&sale){
	items.insert(shared_ptr<Quote>(move(sale.clone())));//clone函数是虚函数，sale的动态类型决定了到底运行quote还是bulk的函数 
} 

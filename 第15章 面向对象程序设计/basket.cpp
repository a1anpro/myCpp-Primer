#include "basket.h"

double Basket::total_receipt(ostream &os) const{
	//��ӡÿ���������������������ܵ����ѽ��
	double sum = 0.0;
	
	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)){
		sum += print_total(os, **iter, items.count(*iter));
	}
	
	os << "Total sales:" << sum << endl;//��ӡ�����ܶ�
	return sum; 
}

//������������ 
void Basket::add_item(const Quote &sale){
	items.insert(shared_ptr<Quote>(sale.clone()));
}
//�ƶ���������
void Basket::add_item(Quote &&sale){
	items.insert(shared_ptr<Quote>(move(sale.clone())));//clone�������麯����sale�Ķ�̬���;����˵�������quote����bulk�ĺ��� 
} 

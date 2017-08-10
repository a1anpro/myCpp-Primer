#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;

class Person;//��ǰ��������ǰ�ã�����
ostream& print(ostream &os, const Person &p);
istream& read(istream &is, Person &p);

class Person {
	friend ostream& print(ostream& os, const Person &p);//���ں����ⶼ��Ҫ����������������
	friend istream& read(istream& is, Person &p);
public:
	//���캯��
	Person() =default;//�൱�ںϳɵ�Ĭ�Ϲ��캯����Ϊ�˱���ʹ�ñ�Ĺ��캯���������Զ�����
	Person(const string name, const string address):name(name),address(address){}//��const���Խ��ܳ���
	explicit Person(istream &is) { read(is, *this); }//����explicit��Ĺ��캯��ֻ��ʹ��ֱ�ӳ�ʼ�������������ÿ�����ʼ����
	
	string getName() const{
		return name;
	}
	string getAddress() const {
		return address;
	}
//private:
	string name;
	string address;
};

#endif
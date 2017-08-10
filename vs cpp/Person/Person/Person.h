#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;

class Person;//提前声明，提前用！！！
ostream& print(ostream &os, const Person &p);
istream& read(istream &is, Person &p);

class Person {
	friend ostream& print(ostream& os, const Person &p);//类内和类外都需要声明这两个函数。
	friend istream& read(istream& is, Person &p);
public:
	//构造函数
	Person() =default;//相当于合成的默认构造函数，为了避免使用别的构造函数而不能自动生成
	Person(const string name, const string address):name(name),address(address){}//用const可以接受常量
	explicit Person(istream &is) { read(is, *this); }//加了explicit后的构造函数只能使用直接初始化，而不可以用拷贝初始化。
	
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
#include <iostream>
using namespace std;

struct Employee{
	Employee(){
		_id = _inc++;
	}
	Employee(const string &n):_name(n){
		_id = _inc++;
	}
	const int id() const{
		return _id;
	}
	Employee(const Employee &e)=delete;
	Employee& operator=(const Employee &e)=delete;//声明为删除函数，声明且不定义 
		
	static int _inc;//静态成员 
	string _name;
	int _id;
};

int Employee::_inc = 1;

int main(){
	Employee e;
	Employee t("yan");
	cout << e.id()<<endl;
	cout << t.id()<<endl;
	return 0;
}

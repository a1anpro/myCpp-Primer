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
	Employee& operator=(const Employee &e)=delete;//����Ϊɾ�������������Ҳ����� 
		
	static int _inc;//��̬��Ա 
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

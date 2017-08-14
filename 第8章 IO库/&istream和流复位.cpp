#include <iostream>
#include <sstream>
using namespace std;

istream& func(istream& is)
{
	int vi = 0;
	auto old_state = is.rdstate();//����is����ԭʼ״̬ 
	
	while (is >> vi){
		cout << vi << endl;
	}
	
	is.setstate(old_state);
	//����ֱ����is.clear();//���Ǹ����غ����������ܲ����İ汾�������λ�����д����־�� 
	return is;
}

istream& func1(istream &is){
	string str;
	while (is >> str){
		cout << str << endl;
	}
	is.clear();
	return is;
}

int main(){
	//func(cin);
	string str = "hello world";
	istringstream iss(str);
	func1(iss);
	return 0;
} 

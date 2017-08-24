#include <iostream>
using namespace std;
#include <sstream>

template<typename T>
string debug_rep(const T &t){
	//const T&可以接受任何类型
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T>
string debug_rep(T *t){
	ostringstream ret;
	ret << t ;
	ret << " point to ";
	if (t){
		ret << debug_rep(*t);
	}
	else{
		ret << "no where";
	}
	return ret.str();
}
//no template version
string debug_rep(const string &str){
	return str;
}
string debug_rep(string *str){
	return debug_rep(string(*str));
}
string debug_rep(const string *str){
	return debug_rep(string(*str));
}

template<typename T>
ostream& print(ostream &os, const T &t){//不可变参数的函数模板要提前声明
	os << t;
	return os; 
}
template<typename T, typename ... Args>
ostream& print(ostream &os, const T &t, const Args&...args){
	os << t;
	cout << endl;
	return print(os, args...);
}

template<typename ...Args>
ostream& errorMsg(ostream &os, const Args...args){
	return print(os, debug_rep(args)...);
}

int main(){
	
	errorMsg(cout, 1, 2, "hello");
	
	return 0;
}

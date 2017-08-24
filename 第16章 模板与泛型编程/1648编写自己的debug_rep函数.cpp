#include <iostream>
using namespace std;
#include <sstream>
//
template<typename T>string debug_rep(const T &t);
template<typename T> string debug_rep(T *t);

string debug_rep(const string &);
string debug_rep(const char *);
string debug_rep(char *);



int main(){
	string s = "hello";
	const string *sp = &s;
	//cout << debug_rep("hello");//"hello"是const char*类型，所以T是char* 
	cout << debug_rep(sp);
	return 0;
} 
template<typename T>
string debug_rep(const T &t){
	ostringstream oss;
	oss << t;
	return oss.str();
}
template<typename T>
string debug_rep(T *t){
	ostringstream oss;
	oss << "Pointer:" << t;
	if (t){
		oss << " " << debug_rep(*t);
	}
	else{
		oss << " null pointer";
	}
	return oss.str();
}

string debug_rep(const string &rhs)
{
	return debug_rep(rhs);
}
string debug_rep(const char *rhs)
{
	return debug_rep(string(rhs));
}
string debug_rep(char *rhs)
{
	return debug_rep(string(rhs));
}




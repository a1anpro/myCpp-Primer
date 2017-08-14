#include <iostream>
using namespace std;

class Debug{
public:
	constexpr Debug(bool b = true):rt(b),io(b),other(b){}//因为是字面值常量类所以可以用
	//字面值常量类必须包括一个constexpr的构造函数
	constexpr Debug(bool r, bool i, bool o):rt(r),io(i),other(o){}
	
	bool any(){ return rt || io || other; }
	
	void set_rt(bool b){rt = b;}
	void set_io(bool b){io = b;}
	void set_other(bool b){other = b;}
	
private:
	bool rt;//runtime error
	bool io;//I/O error
	bool other; // the other error 
};

int main(){
	return 0;
}

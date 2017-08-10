#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
struct HasPtr{
	friend void swap(HasPtr &lhs, HasPtr &rhs);
	friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
	
	HasPtr(const string &s=string()):i(0),ptr(new string(s)){}//用了默认参数，所以可以当作默认构造函数使用 
	HasPtr(const HasPtr &hp):i(hp.i), ptr(new string(*hp.ptr)){	}
	HasPtr& operator=(const HasPtr &hp){
		//先拷贝值，然后再释放原来的控件
		auto new_ptr = new string(*hp.ptr);
		delete ptr;
		ptr = new_ptr;
		i = hp.i;
		return *this; 
	}
	~HasPtr(){
		delete ptr;
	}
	
	int i;
	string *ptr;
};

bool operator<(const HasPtr &lhs, const HasPtr &rhs){
	return *lhs.ptr < *rhs.ptr;
}

inline void swap(HasPtr &lhs, HasPtr &rhs){
		//using std::swap;//如果自定义了swap就不会调用std的 
		swap(lhs.ptr, rhs.ptr);
		swap(lhs.i, rhs.i);
		cout << "调用自定义swap"<<endl; 
}

int main(){
	vector<HasPtr> vec;
	vec.push_back(HasPtr("yanhui"));
	vec.push_back(HasPtr("zhouyi"));
	
	sort(vec.begin(), vec.end());
	
	return 0;
}

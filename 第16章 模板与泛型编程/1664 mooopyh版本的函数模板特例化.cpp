#include <iostream>
using namespace std;
#include <vector>

template<typename T>
size_t count(const vector<T> &vec, T val){
	size_t cnt = 0;
	for (const auto &i : vec){
		if (i == val){
			++cnt;
		}
	}
	return cnt;
}

template<>//模板函数特例化，处理指向字符的指针（而不是数组） 
size_t count(const vector<const char*> &vec, const char* val){
	size_t cnt = 0;
	for (const auto &i : vec){
		if (i == val){
			++cnt;
		}
	}
	return cnt;
}

int main(){
//	vector<int> vi{1,2,3,1,1,1,1};
//	cout << count(vi, 1) <<endl;
	
	vector<string> vs = {"hello", "ok", "ok"};
	cout << count(vs, string("ok")) <<endl;
	
//	vector<const char*> vc = {"hello", "ok", "ok"};
//	cout << count(vc, "ok") << endl;//"ok"是字符数组，而字符数组不能转换成指针 
	
	
	return 0;
}

#include <iostream>
using namespace std;
#include <vector>

template<typename T>
size_t count(const T &val, const vector<T> &vec){
	size_t cnt = 0;
	for (const auto &i : vec){
		if (i == val){
			++cnt;
		}
	}
	return cnt;
}

template<unsigned N>
size_t count(const char (&val)[N], const vector<const char*> &vec){
	size_t cnt = 0;
	for (const auto &i : vec){
		if (i == val){
			++cnt;
		}
	}
	return cnt;
}

template<>//ģ�庯��������������ָ���ַ���ָ�루���������飩 
size_t count(const char* const &val, const vector<const char*> &vec){
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
//	cout << count(1, vi) <<endl;
//	
//	vector<string> vs = {"hello", "ok", "ok"};
//	cout << count(string("ok"), vs) <<endl;
	
	//const char *c = "ok";
	vector<const char*> vc = {"hello", "ok", "ok"};
	//cout << count(c, vc) <<endl;
	cout << count("ok", vc) << endl;//"ok"���ַ����飬���ַ����鲻��ת����ָ�� 
	
	
	return 0;
}

#include <iostream>
using namespace std;
#include <vector>

template<typename T>
void Foo(const T &t){
	for (typename T::size_type i = 0; i != t.size(); ++i){
		cout << t[i] <<endl;
	}
}

template<typename T>
void Foo1(const T &t){
	for(auto beg = t.begin(); beg != t.end(); ++beg){
		cout << *beg <<endl;
	}
}

int main(){
	vector<int> vec{1,2,3,4};
	
	Foo1(vec);
	
	return 0;
}

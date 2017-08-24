#include <iostream>
using namespace std;

template<typename T>
struct Foo{
	Foo(T t):a(t){
		cout << a<<endl;
	}
	T a;
};
extern template class Foo<int>;
template class Foo<int>;

int main(){
	Foo<int> f(1);
	
	return 0;
}

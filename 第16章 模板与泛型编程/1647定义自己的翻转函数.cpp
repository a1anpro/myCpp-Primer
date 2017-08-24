#include <iostream>
#include <utility>
using namespace std;

void f(int&& a, int&& b){
	cout << a << " " << b <<endl;
}

template<typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main(){
	flip(f, 1, 2);//此例中T1/T2都是int& 
	
	return 0;
}

#include <iostream>
#include <memory>
#include <utility>
using namespace std;

// Exercise 16.60:
// Explain how make_shared (¡ì 12.1.1, p. 451) works.
//
//  make_shared shoudl be a variadic template function that forwards all arguments to
//  underlying constructors that allocate and initializes an object in dynamic memory and
//  , at last, build a shared_ptr by wrapping the raw pointer.
//
// Exercise 16.61:
// Define your own version of make_shared

template<typename T, typename...Args>
shared_ptr<T> my_make_shared(Args&&...args){
	return shared_ptr<T>(new T(forward<Args>(args)...));
}

int main(){
	
	shared_ptr<int> sp = my_make_shared<int>(10);
	
	cout << *sp<<endl;
	
	return 0;
}

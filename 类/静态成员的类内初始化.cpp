#include <iostream>
using namespace std;

//class Account{
//public:
//	
//private:
//	static const char chr;
//	static constexpr int period = 10;
//};
//constexpr int Account::period;
//int main(){
//	
//	
//	return 0;
//}
#include <vector>
class Example{
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 10;
	static vector<double> vec;
};
//constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);

int main(){
	
	return 0;
}

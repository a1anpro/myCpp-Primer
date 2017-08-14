#include <iostream>
using namespace std;

class Y;
class X{
public:
	Y *py = nullptr;//因为Y类还没有定义，所以只能有Y的引用和指针 
};
class Y{
public:
	X xitem;
};
int main(){
	
	return 0;
}

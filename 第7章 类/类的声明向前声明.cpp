#include <iostream>
using namespace std;

class Y;
class X{
public:
	Y *py = nullptr;//��ΪY�໹û�ж��壬����ֻ����Y�����ú�ָ�� 
};
class Y{
public:
	X xitem;
};
int main(){
	
	return 0;
}

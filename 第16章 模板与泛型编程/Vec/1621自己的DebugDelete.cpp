#include <iostream>
#include <memory>
using namespace std;

//��ͨ�������Աģ�� 
class DebugDelete{
public:
	DebugDelete(ostream &s = cerr):os(s){}
	
	template<typename T>
	void operator()(T *d){
		os << "deleteing unique_ptr"<<endl;
		delete d;//
	}
private:
	ostream &os;
};

int main(){
	unique_ptr<int, DebugDelete> up(new int, DebugDelete());
	cout << "hello" <<endl;
	return 0;
} 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo{
public:
	Foo sorted() &&;//��ֵthis����
	Foo sorted() const &;//��ֵthis���� 

	vector<int> data;
};

Foo Foo::sorted() &&{
	cout << "������ֵ"<<endl;
	sort(data.begin(), data.end());
	return *this;//�Ѿ����� 
}

Foo Foo::sorted() const &{
	//this����ֵ�����ܸ���
	cout << "������ֵ"<<endl;
//	Foo ret(*this);//��this������ͬ��
//	sort(ret.data.begin(), ret.data.end()); 
//	return ret;

	return Foo(*this).sorted();
}

int main(){
	//Foo().sorted();
	
	Foo f;
	f.sorted();
	return 0;
}

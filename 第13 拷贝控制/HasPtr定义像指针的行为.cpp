#include <iostream>
using namespace std;

class HasPtr{
public:
	//���캯�������µ�string ���µļ�����������������Ϊ1 
	HasPtr(const string &s = string()):
		ps(new string(s)),i(0),use(new size_t(1)){}
	//�������캯�������������ݳ�Ա��������������
	HasPtr(const HasPtr &rhs):
		ps(rhs.ps),i(rhs.i),use(rhs.use){
			++*use;
		} 
	HasPtr& operator=(const HasPtr&);
	~HasPtr();	
	
private:
	string *ps;
	int i;
	size_t *use;//������¼�ж��ٸ�������*ps��Ա 
};

HasPtr::~HasPtr(){
	//���use�ݼ����Ϊ0�����ͷ�
	if (--*use==0){
		delete use;
		delete ps;
	} 
}

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	//Ӧ�ð������Ϳ�������Ĺ��������ˡ���Ϊ�ݼ���ֵ��use�����Ϊ0��Ҫ�ͷ�
	//���������ֵ����������ô������ͷŵĻ��ͻ�δ������������ȵ�����ֵ
	
	++*(rhs.use);
	if (--*use==0){
		delete use;//���û�������û������ͷű��������ĳ�Ա�� 
		delete ps;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

int main(){
	
	
	return 0;
}

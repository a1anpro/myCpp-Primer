#include <iostream>

using namespace std;

class HasPtr{
public:
	//���캯�� 
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0){}
	//�������캯��
	HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
	
	HasPtr& operator=(const HasPtr &hp){
		string *new_ptr = new string(*hp.ps);
		//��Ϊps���滻���µ��ˣ�����Ҫdelete 
		delete ps;
		ps = new_ptr;
		i = hp.i;
		return *this;//��ֵ�����ǽ�ԭ���ĸ��ǡ�
	}	
	//��������
	~HasPtr(){
		delete ps;//����������Ϊ�������֣������� �� �������֡������帺���ͷŶ���̬�������Դ�������������ٷ�static���� 
	} 
private:
	string *ps;
	int i;
}; 
int main(){
	return 0;
}

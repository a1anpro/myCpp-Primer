#include <iostream>
using namespace std;

int main(){
	string str("ab2c3d7R4E6");
	string numbers="0123456789";
	string alpha="a";
	
	for (int i=1;i!=26;++i){
		alpha+= 'a'+i;
	}
	for (int i=0;i!=27;++i){
		alpha+='A'+i;
	}
	
	string::size_type pos = 0;
	while ((pos=str.find_first_of(numbers, pos)) != string::npos)//û�е��Ҳ�����ʱ��ͼ��� 
	{
		cout << "number index: " << pos << " : " << str[pos]<<endl;
		++pos;//����Ҫ����
	}
	cout << "-----------------------------------"<<endl;
	pos = 0;//����Ҫ���� 
	while ((pos=str.find_first_of(alpha, pos)) != string::npos)//û�е��Ҳ�����ʱ��ͼ��� 
	{
		cout << "alpha index: " << pos << " : " << str[pos]<<endl;
		++pos;//����Ҫ����
	}
	
	return 0;
}

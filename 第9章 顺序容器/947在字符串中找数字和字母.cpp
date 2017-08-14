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
	while ((pos=str.find_first_of(numbers, pos)) != string::npos)//没有到找不到的时候就继续 
	{
		cout << "number index: " << pos << " : " << str[pos]<<endl;
		++pos;//必须要递增
	}
	cout << "-----------------------------------"<<endl;
	pos = 0;//用完要置零 
	while ((pos=str.find_first_of(alpha, pos)) != string::npos)//没有到找不到的时候就继续 
	{
		cout << "alpha index: " << pos << " : " << str[pos]<<endl;
		++pos;//必须要递增
	}
	
	return 0;
}

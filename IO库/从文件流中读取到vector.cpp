#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream istrm("vectorStr.txt");
	vector<string> vstr;
	string tempstr;
	
	if (istrm)//����ļ��Ƿ񱻳ɹ��� 
	{
		while (getline(istrm, tempstr))
		{
			vstr.push_back(tempstr);
		}
		
		for (const auto &str : vstr)//��const������Ч�ʸ��߼����Ը��ߡ� 
		{
			cout << str << endl;
		}
		
		istrm.close();
	}
	else{
		cerr << "can not open the file"<<endl;
	}
	return 0;
}

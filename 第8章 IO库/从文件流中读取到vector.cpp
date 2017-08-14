#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream istrm("vectorStr.txt");
	vector<string> vstr;
	string tempstr;
	
	if (istrm)//检查文件是否被成功打开 
	{
		while (getline(istrm, tempstr))
		{
			vstr.push_back(tempstr);
		}
		
		for (const auto &str : vstr)//用const的引用效率更高兼容性更高。 
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

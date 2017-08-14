#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void func(const string &filename){
	ifstream ifs(filename);//��filename���ļ�
	vector<string> vstr;
	string temp;
	
	if (ifs)
	{
		while (getline(ifs, temp))
		{
			vstr.push_back(temp);//���ļ��ж��������з���vector 
		}
		for (const auto &str : vstr)
		{
			istringstream iss(str);
			while (iss >> temp)
			{
				cout << temp <<endl;
			}
		}
	} 
	
}

int main(){
	string filename = "vectorStr.txt";
	func(filename);
	
	return 0;
}

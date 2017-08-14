#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>

int main(){
	string upOut="bdfhkt";
	string lowOut="gpqy";	
	string fileName="words.txt";
	ifstream ifstrm(fileName);
	
	if (ifstrm)
	{
		//如果文件打开成功，则从中读取
		//将单词一行一行读入到istringstream做处理
		string temp;
		while (getline(ifstrm, temp))
		{
			istringstream iss(temp);//用读出来的一行来初始化istringstream; 
			while (iss>>temp)
			{
				if (temp.find_first_of(upOut)!=string::npos || temp.find_first_of(lowOut)!=string::npos){
					//只要碰到出头的 就跳过
					continue; 
				}
				else{
					cout << temp<<endl;
				}
			}
		}	
	}
	
	return 0;
}


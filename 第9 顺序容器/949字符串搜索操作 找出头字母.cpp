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
		//����ļ��򿪳ɹ�������ж�ȡ
		//������һ��һ�ж��뵽istringstream������
		string temp;
		while (getline(ifstrm, temp))
		{
			istringstream iss(temp);//�ö�������һ������ʼ��istringstream; 
			while (iss>>temp)
			{
				if (temp.find_first_of(upOut)!=string::npos || temp.find_first_of(lowOut)!=string::npos){
					//ֻҪ������ͷ�� ������
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


#include <iostream>
using namespace std;

class MyDate{
public:
	MyDate(const string &str);
	unsigned year;
	unsigned month;
	unsigned day;
};

int main(){
	MyDate date("99/1/1997");
	cout << date.day << ":" << date.month << ":" <<date.year<<endl;
	return 0;
}

MyDate::MyDate(const string &str)
{
	//构造函数
	unsigned format = 0;
	
	//格式1：1/1/1990
	if (str.find_first_of("/") != string::npos)
	{
		format = 0x10;//只要找到了/，就将格式设置 
	}
	
	//格式2：Jan 1,1900 / January 1, 1990
	else if (str.find_first_not_of(",")!=string::npos)
	{
		format = 0x01;//只要是碰到了字母的，就是这个格式 
	}
	
	switch (format){
		case 0x10:
		{
			day = stoi(str.substr(0, str.find_first_of("/")));
			cout << day<<endl;
			month = stoi(str.substr(str.find_first_of("/") + 1,
                                   str.find_last_of("/") - str.find_first_of("/")-1));
        	cout << month<<endl;
			year = stoi(str.substr(str.find_last_of("/")+1, 4));
			//substr(pos,n);//pos是位置，n是个数			
		}
		break;
		case 0x01:
		{
			day = stoi(str.substr(str.find_first_of("0123456789"), 
						str.find_first_of(",")-str.find_first_of("0123456789")));
			if (str.find("Jan") < str.size()) month = 1;
			if (str.find("Feb") < str.size()) month = 2;
			if (str.find("Mar") < str.size()) month = 3;
			if (str.find("Apr") < str.size()) month = 4;
			if (str.find("May") < str.size()) month = 5;
			if (str.find("Jun") < str.size()) month = 6;
			if (str.find("Jul") < str.size()) month = 7;
			if (str.find("Aug") < str.size()) month = 8;
			if (str.find("Sep") < str.size()) month = 9;
			if (str.find("Oct") < str.size()) month = 10;
			if (str.find("Nov") < str.size()) month = 11;
			if (str.find("Dec") < str.size()) month = 12;
			
			year = stoi(str.substr(str.find_first_of(" ")+1, 4));
		}
		break;
	} 
	 
}

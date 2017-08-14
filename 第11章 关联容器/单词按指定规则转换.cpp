#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void word_transform(ifstream &rule_file, ifstream &text_file);//主调函数，用来管理调用别的函数 
void get_Rulemap(map<string,string> &ruleMap, ifstream &rule_file);
const string &transform(const string &word, map<string,string> &ruleMap);

int main(){
	ifstream rule_file("ruleFile.txt");
	ifstream text_file("textFile.txt");
	
	if (rule_file && text_file)
	{
		//都打开了才能调用别的
		word_transform(rule_file, text_file); 
	}
	
	return 0;
}

void word_transform(ifstream &rule_file, ifstream &text_file)//主调函数，用来管理调用别的函数 
{
	//通过规则文件 建立map，以便查找 
	map<string, string> ruleMap;//构建空的map
	get_Rulemap(ruleMap, rule_file); //得到了规则map，现在要读取文本内容进行替换
	
	string line;
	while (getline(text_file, line))
	{
		istringstream iss(line);
		//对于每个单词，查找是否在map中，如果在的话，就将它替换
		bool isFirst = true;
		string word;
		while (iss>>word){
			if (isFirst) isFirst=false;
			else{
				cout << " ";
			}
			//对于每个单词是否在map中有对应。我们另外构建一个函数
			cout << transform(word, ruleMap); 
		} 
	} 
}

void get_Rulemap(map<string,string> &ruleMap, ifstream &rule_file)
{
	//打开文件，并读取内容
	string line;
	while (getline(rule_file, line))
	{
		istringstream iss(line);
		string key,value;
		iss>>key>>value;
		ruleMap[key] = value;
		//ruleMap.insert({key, value});
	}
}

const string &transform(const string &word, map<string,string> &ruleMap)//返回的是传进来的引用，不存在销毁 
{
	auto find_it = ruleMap.find(word);
	if (find_it!=ruleMap.end())//找到了
	{
		return find_it->second;
	} 
	else
	{
		return word; 
	}
}


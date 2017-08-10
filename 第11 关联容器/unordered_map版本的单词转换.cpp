#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

unordered_map<string,string> getMap(ifstream &ruleFile){
	unordered_map<string,string> ruleMap;//构建空map
	string key, value;//
	
	while (ruleFile>>key && getline(ruleFile, value))//因为值可能是短语，中间有空格,不能用>> 
	{
		if (value.size() > 1)//如果值不为空，就存 
		{
			ruleMap[key] = value.substr(1);//getline得到的是包含空格的，要从1开始把空格丢掉 
		}
		else
		{
			//抛出错误
			throw runtime_error("no rule for " + key); 
		}
	} 
	return ruleMap;
}

const string &transform(const string &word, const unordered_map<string,string> &ruleMap)
{
	auto find_it = ruleMap.find(word);
	if (find_it != ruleMap.end()){
		return find_it->second;
	}
	else
	{
		return word;
	}
}

void word_transform(ifstream &ruleFile, ifstream &textFile){
	unordered_map<string,string> ruleMap = getMap(ruleFile);
	string line;//用来处理textFile
	while (getline(textFile, line)){
		istringstream iss(line);//处理文本中出现的每个单词
		bool isFirst = true;
		string word;
		while (iss>>word){
			if (isFirst) isFirst = false;//表示第一个单词已经读完了
			else cout << " ";//不是第一个的话就要先打印空格
			cout << transform(word, ruleMap); 
		}
	} 
}

int main(){
	ifstream ruleFile("ruleFile.txt");
	ifstream textFile("textFile.txt");
	
	if (ruleFile&&textFile){
		word_transform(ruleFile, textFile);
	}
	
	return 0;
}

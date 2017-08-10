#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

unordered_map<string,string> getMap(ifstream &ruleFile){
	unordered_map<string,string> ruleMap;//������map
	string key, value;//
	
	while (ruleFile>>key && getline(ruleFile, value))//��Ϊֵ�����Ƕ���м��пո�,������>> 
	{
		if (value.size() > 1)//���ֵ��Ϊ�գ��ʹ� 
		{
			ruleMap[key] = value.substr(1);//getline�õ����ǰ����ո�ģ�Ҫ��1��ʼ�ѿո񶪵� 
		}
		else
		{
			//�׳�����
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
	string line;//��������textFile
	while (getline(textFile, line)){
		istringstream iss(line);//�����ı��г��ֵ�ÿ������
		bool isFirst = true;
		string word;
		while (iss>>word){
			if (isFirst) isFirst = false;//��ʾ��һ�������Ѿ�������
			else cout << " ";//���ǵ�һ���Ļ���Ҫ�ȴ�ӡ�ո�
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

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void word_transform(ifstream &rule_file, ifstream &text_file);//��������������������ñ�ĺ��� 
void get_Rulemap(map<string,string> &ruleMap, ifstream &rule_file);
const string &transform(const string &word, map<string,string> &ruleMap);

int main(){
	ifstream rule_file("ruleFile.txt");
	ifstream text_file("textFile.txt");
	
	if (rule_file && text_file)
	{
		//�����˲��ܵ��ñ��
		word_transform(rule_file, text_file); 
	}
	
	return 0;
}

void word_transform(ifstream &rule_file, ifstream &text_file)//��������������������ñ�ĺ��� 
{
	//ͨ�������ļ� ����map���Ա���� 
	map<string, string> ruleMap;//�����յ�map
	get_Rulemap(ruleMap, rule_file); //�õ��˹���map������Ҫ��ȡ�ı����ݽ����滻
	
	string line;
	while (getline(text_file, line))
	{
		istringstream iss(line);
		//����ÿ�����ʣ������Ƿ���map�У�����ڵĻ����ͽ����滻
		bool isFirst = true;
		string word;
		while (iss>>word){
			if (isFirst) isFirst=false;
			else{
				cout << " ";
			}
			//����ÿ�������Ƿ���map���ж�Ӧ���������⹹��һ������
			cout << transform(word, ruleMap); 
		} 
	} 
}

void get_Rulemap(map<string,string> &ruleMap, ifstream &rule_file)
{
	//���ļ�������ȡ����
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

const string &transform(const string &word, map<string,string> &ruleMap)//���ص��Ǵ����������ã����������� 
{
	auto find_it = ruleMap.find(word);
	if (find_it!=ruleMap.end())//�ҵ���
	{
		return find_it->second;
	} 
	else
	{
		return word; 
	}
}


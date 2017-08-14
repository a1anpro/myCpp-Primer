#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
	//��map�����浥�ʺ��к�
	map<string, list<size_t>> word_pos;
	ifstream istrm("text.txt");
	size_t line_num = 1;
	string line;
	while (getline(istrm, line)){
		//���ļ��е�һ�ж���line�����ҽ��кŴ��뵥��
		istringstream iss(line);
		string word;
		while (iss >> word){
			word_pos[word].push_back(line_num);//��ÿ�����ʳ��ֵ�λ�ô���list 
		}
		++line_num;
	} 
	
	for (const auto &w:word_pos){
		cout << w.first << " in: ";
		for (const auto &t:w.second){
			cout << t << " ";
		}
		cout <<endl;
	}
	
	return 0;
}

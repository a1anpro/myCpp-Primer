#include <iostream>
#include <map>

using namespace std;

int main(){
	multimap<string, string> writer;
	
	writer.emplace("yanhui", "hello");
	writer.emplace("yanhui", "hello1");
	writer.emplace("zhoujgasd", "world");	
	writer.emplace("yanhui", "hello2");
		
//	auto it = writer.find("yanhui");
//	if (it != writer.end())
//		writer.erase(it);
	
	string author = "yanhui";
	string work = "hello1";
	for (auto found = writer.find(author); found!=writer.end() && found->first==author; ){
		if (found->second==work) writer.erase(found);
		else ++found;//�����������ߣ����Ҳ���Ҫɾ������Ʒ���������ƶ�����Ϊ��������һ��� 
	}
	
	for (const auto &i:writer){
		cout << i.first << " " << i.second<<endl;
	}
	
	return 0;
} 

#include <iostream>
using namespace std;

void func(string &str, const string &oldVal, const string &newVal){
	//��str����oldVal
	
	//���ʣ�೤�Ȼ���û�� oldVal��
	for (auto beg = str.begin(); distance(beg,str.end()) >= distance(oldVal.begin(),oldVal.end()); ){
		if (string{beg,beg+oldVal.size()} == oldVal)
		{
			//�ҵ����Ӵ�,�滻
			//str.replace(beg-str.begin(), oldVal.size(), newVal);
			//##�ò���replace������erase��insert
			beg = str.erase(beg, beg + oldVal.size());
            beg = str.insert(beg, newVal.begin(), newVal.end());
			advance(beg, newVal.size()); 
		} 
		else{
			++beg;
		}
	}
}

int main(){
	string str = "abcdefthoaaaa";
	string oldVal = "tho", newVal = "though";
	
	func(str,oldVal, newVal);
	
	cout << str;
	return 0;
}

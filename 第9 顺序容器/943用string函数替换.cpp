#include <iostream>
using namespace std;

void func(string &str, const string &oldVal, const string &newVal){
	//在str中找oldVal
	
	//检查剩余长度还有没有 oldVal长
	for (auto beg = str.begin(); distance(beg,str.end()) >= distance(oldVal.begin(),oldVal.end()); ){
		if (string{beg,beg+oldVal.size()} == oldVal)
		{
			//找到了子串,替换
			//str.replace(beg-str.begin(), oldVal.size(), newVal);
			//##用不了replace，换成erase和insert
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

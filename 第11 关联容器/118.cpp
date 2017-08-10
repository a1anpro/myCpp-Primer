#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<string> vst = {"aa","bb","cc"};
	for (string word; cin >> word;){
		if (find(vst.begin(), vst.end(), word) != vst.end()){
			cout << "word included"<<endl;
		}
		else{
			vst.push_back(word);
		}
	}
	
	for (const auto &s : vst){
		cout << s<< " ";
	}
	
	return 0;
}

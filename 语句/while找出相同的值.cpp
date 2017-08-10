#include <iostream>
using namespace std;
#include <vector>
int main(){
	vector<string> vs;
	
	string word;
	bool close = false;
	while (cin >> word){// && !vs.empty()
		for (const auto &x : vs){
			if (word==x){
				close = true;
			}
		}
		if (close){
			cout << word<<endl;
			break;
		}
		vs.push_back(word);
	}
	
	return 0;
}

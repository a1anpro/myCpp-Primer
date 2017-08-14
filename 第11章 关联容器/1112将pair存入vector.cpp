#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	vector<pair<string, int>> vp;
	string s;
	int i;
	pair<string,int> p;
	while (cin >> s >> i){
		vp.emplace_back(s,i);//emplace_back构造一个对象并插入。 
		//vp.push_back({s,i});
		//vp.push_back(pair<string, int>(s,i)); 
		//vp.push_back(make_pair(s, i));
	}
	
	for (auto i:vp){
		cout << i.first << " " << i.second<<endl;
	}
	
	return 0;
}

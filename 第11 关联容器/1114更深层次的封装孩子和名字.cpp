#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include <utility>

class Families{
public:
	using Child = pair<string, string>;//存孩子的名字和生日
	using Children = vector<Child>;
	using Data = map<string, Children>;//存祖辈的名字和孩子的信息
	 
	void add(const string &lastName, const string &firstName, const string &birthday){
		_data[lastName].push_back({firstName, birthday});
	}
	
	ostream &print(ostream &os) const{
		if (_data.empty()) return os<<"no data right now"<<endl;
		
		for (const auto &i:_data){
			os << i.first<<":\n";
			for (const auto &child:i.second){
				os << child.first << " " << child.second<<endl;
			}
			os << endl;
		}
		return os;
	}
	
private:
	Data _data;
};

int main(){
	
	return 0;
}

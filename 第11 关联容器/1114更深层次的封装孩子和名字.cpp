#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include <utility>

class Families{
public:
	using Child = pair<string, string>;//�溢�ӵ����ֺ�����
	using Children = vector<Child>;
	using Data = map<string, Children>;//���汲�����ֺͺ��ӵ���Ϣ
	 
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

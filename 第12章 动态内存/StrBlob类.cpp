#include <iostream>
using namespace std;
#include <vector>
#include <memory>
#include <initializer_list>
class StrBlob{

public:
	typedef  vector<string>::size_type size_type;//����������vector�����ͳ�Ա����Ϊ��������ͳ�Ա
	StrBlob():data(make_shared<vector<string>>()){};//make_shared�����ṩ��ʼ���Ĳ������ò������ݸ�T�Ĺ��캯�� 
	StrBlob(initializer_list<string> il):
										data(make_shared<vector<string>>(il)){};//����һ��initializer_list�Ķ�����Ϊ�������.vector���Խ���il 
	
	size_type size() const{return data->size();}
	bool empty() const {return data->empty();}
	
	//��Ӻ�ɾ��Ԫ��
	void push_back(const string &t){
		data->push_back(t);
	} 
	void pop_back();
	
	//Ԫ�ط���,��const�汾 
	string& front();
	string& back(); 
	//const�汾
	const string& front() const{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string& back() const;
	
private:
	shared_ptr<vector<string>> data;//ָ��vector������ָ��
	//���data[i]���Ϸ� �׳�msg�쳣 
	void check(size_type i, const string &msg)const; 
};

void StrBlob::check(size_type i, const string &msg)const{
	if (i>=data->size()){
		throw out_of_range(msg);//�׳��쳣 
	}
}
string& StrBlob::front(){
	//��Ҫ����check����飬����ɹ��Ļ����õײ��vector��������Լ��Ĺ�����
	check(0, "front on empty StrBlob");
	return data->front(); 
}
string& StrBlob::back(){
	//��Ҫ����check����飬����ɹ��Ļ����õײ��vector��������Լ��Ĺ�����
	check(0, "back on empty StrBlob");
	return data->back(); 
}
const string& StrBlob::back() const{//Ϊʲôֻ�������ڶ��壿 
		check(0, "back on empty StrBlob");
		return data->back();
}
void StrBlob::pop_back(){
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}



int main(){
	
	return 0;
}

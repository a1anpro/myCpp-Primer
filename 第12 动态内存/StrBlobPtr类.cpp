#include <iostream>
using namespace std;
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlobPtr;
class StrBlob{
public:
	friend class StrBlobPtr;//�Ա���StrBlobPtr�й��캯����ʹ�� 
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
	
	//����begin()��end()������ָ�������Լ���StrBlobPtr
	StrBlobPtr begin();
	StrBlobPtr end();
	
private:
	shared_ptr<vector<string>> data;//ָ��vector������ָ��
	//���data[i]���Ϸ� �׳�msg�쳣 
	void check(size_type i, const string &msg)const; 
};

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}

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

class StrBlobPtr{
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz=0):wptr(a.data),curr(sz){}
	
	string& deref() const;
	StrBlobPtr& incr();//ǰ׺���� 
private:
	//������ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<string>> check(size_t,const string&) const;
	
	//����һ��weak_ptr,��ζ�ŵײ�vector���ܱ�����
	weak_ptr<vector<string>> wptr;
	size_t curr;//�������еĵ�ǰλ�á� 
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg)const{ 
	//���ָ��ָ���vector�Ƿ񻹴���
	auto ret = wptr.lock();//w.expired()���use_count()Ϊ0�򷵻�true�����expiredΪtrue������һ���յ�shared_ptr;���򷵻�һ��ָ��w�����sp
	//��˼���ǣ������wptr��������>=1�����ܵõ�ָ��wptr��shared_ptr
	if (!ret)
	{
		//�����ָ��������
		throw runtime_error("unbound StrBlobPtr"); 
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);//�����ָ��vector�±곬�硣���׳����� 
	}
	return ret;//���򷵻�ָ��vector��shared_ptr 
}

string& StrBlobPtr::deref()const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	//ǰ׺���������ص�����Ķ��������
	auto p = check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}



int main(){
	
	return 0;
}

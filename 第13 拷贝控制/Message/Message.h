#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <iostream>
#include <memory>
#include <set>
using namespace std;

class Folder;
class Message{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	//���캯�� 
	explicit Message(const string &str = ""):contents(str){}
	//�������ƺ���
	//�������캯��:�����ݿ�������Ȼ����ָ��ĳ�ʼ�� 
	Message(const Message &rhs):contents(rhs.contents){
		add_to_Folders(rhs);//��this����rhs���ڵ�Folder 
		//��rhs����Folder����this��folders 
		for (auto i:rhs.folders){
			folders.insert(i);
		}
	}
	//������ֵ����
	Message& operator=(const Message &rhs);
	//�������� 
	~Message();
	
	void print_debug(){
		cout << contents<<endl;
	}
	
	void save(Folder &f);
	void remove(Folder &f);
	
	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	//��Ϣ������
	string contents;
	set<Folder*> folders; 
	
	//�������캯���Ϳ�����ֵ������Ҫ����ָ��Ĳ�����������ͬ�Ĺ��ܿ��Թ����ڲ�������
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder{
public:
	Folder()=default;
	//�������ƺ���
	Folder(const Folder&);
	Folder& operator=(const Folder &rhs);
	~Folder(); 
	
	void print_debug(); 
	
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> messages;
	//��Messageָ�����Folder 
	void add_to_Message(const Folder &rhs);
	void remove_from_Message();
};

#endif

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
	//构造函数 
	explicit Message(const string &str = ""):contents(str){}
	//拷贝控制函数
	//拷贝构造函数:把内容拷贝过来然后，做指向的初始化 
	Message(const Message &rhs):contents(rhs.contents){
		add_to_Folders(rhs);//把this存入rhs所在的Folder 
		//把rhs所在Folder存入this的folders 
		for (auto i:rhs.folders){
			folders.insert(i);
		}
	}
	//拷贝赋值函数
	Message& operator=(const Message &rhs);
	//析构函数 
	~Message();
	
	void print_debug(){
		cout << contents<<endl;
	}
	
	void save(Folder &f);
	void remove(Folder &f);
	
	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	//信息的内容
	string contents;
	set<Folder*> folders; 
	
	//拷贝构造函数和拷贝赋值函数都要进行指向的操作。所以相同的功能可以归结成内部函数。
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder{
public:
	Folder()=default;
	//拷贝控制函数
	Folder(const Folder&);
	Folder& operator=(const Folder &rhs);
	~Folder(); 
	
	void print_debug(); 
	
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> messages;
	//把Message指向这个Folder 
	void add_to_Message(const Folder &rhs);
	void remove_from_Message();
};

#endif

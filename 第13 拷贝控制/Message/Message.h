#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <iostream>
#include <memory>
#include <set>
using namespace std;

class Folder;
class Message{
	friend class Folder;
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
	
	void save(Folder &f);
	void remove(Folder &f);
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
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> messages;
};

#endif

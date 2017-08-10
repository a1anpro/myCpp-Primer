#include "Message.h"

///////////////////////////////////////////////////////////////
//Message Implementation

void swap(Message &lhs, Message &rhs){
	//要交换两个对象所在的Folder
	for (auto p:lhs.folders){
		p->remMsg(&lhs);
	} 
	for (auto p:rhs.folders){
		p->remMsg(&rhs);
	}
	//交换内容
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);//调用各自的swap函数
	//交换之后把对应的folder添加进去
	for (auto p:lhs.folders)
	{
		p->addMsg(&lhs);
	} 
	for (auto p:rhs.folders){
		p->addMsg(&rhs);
	}
}

//把message添加到指定的Folder中
void Message::save(Folder &f){
	folders.insert(&f);//把f的指针添加到folders
	f.addMsg(this); 
} 
//把message从指定的Folder中取出 
void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

void Message::addFldr(Folder *folder){
	folders.insert(folder);
}
void Message::remFldr(Folder *folder){
	folders.erase(folder);
}
//把this添加到m所在的folders 
void Message::add_to_Folders(const Message &m){
	for (auto p:m.folders){
		p->addMsg(this);
	}
}
//把this从包含其的Folder中去除 
void Message::remove_from_Folders(){
	for (auto p:folders){
		p->remMsg(this);
	}
}

Message& Message::operator=(const Message &rhs){
	//通过先删除指针，再插入它们来处理自赋值情况 
	remove_from_Folders();//把this的folders都去除。存入rhs的 
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
Message::~Message(){
	remove_from_Folders();
	/*
	调用remove_from_folders确保没有任何Folder保存正在销毁
	的Message指针。编译器自动调用string的析构函数释放contents
	并自动调用set的析构函数来清理集合成员使用的内存 
	*/
}

///////////////////////////////////////////////////////////////
//Folder Implementation

void Folder::print_debug(){
	for (auto p:messages){
		cout << p->contents<<endl;
	}
}

void Folder::addMsg(Message *m){
	messages.insert(m);
}
void Folder::remMsg(Message *m){
	messages.erase(m);
}

void Folder::add_to_Message(const Folder &rhs){
	for (auto p:rhs.messages){
		p->addFldr(this);
	}
}
void Folder::remove_from_Message(){
	for (auto p:messages){
		p->remFldr(this);
	}
}
////////////////////////////////////////////////////////////
//Folder的拷贝构造函数
Folder::Folder(const Folder &rhs){
	messages = rhs.messages;
	//所有指向rhs的也要指向拷贝的this
	add_to_Message(rhs); 
}
Folder& Folder::operator=(const Folder &rhs){
	//考虑自赋值
	remove_from_Message();
	messages = rhs.messages;
	add_to_Message(rhs);
	return *this;
}
Folder::~Folder(){
	remove_from_Message();//清楚所有再外面指向的指针。set由它的析构收回。 
}

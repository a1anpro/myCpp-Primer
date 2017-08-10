#include "Message.h"

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

void Folder::addMsg(Message *m){
	messages.insert(m);
}
void Folder::remMsg(Message *m){
	messages.erase(m);
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
	remove_from_Folder();
	/*
	调用remove_from_folders确保没有任何Folder保存正在销毁
	的Message指针。编译器自动调用string的析构函数释放contents
	并自动调用set的析构函数来清理集合成员使用的内存 
	*/
}


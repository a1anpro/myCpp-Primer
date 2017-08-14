#include "Message.h"

///////////////////////////////////////////////////////////////
//Message Implementation

void swap(Message &lhs, Message &rhs){
	//Ҫ���������������ڵ�Folder
	for (auto p:lhs.folders){
		p->remMsg(&lhs);
	} 
	for (auto p:rhs.folders){
		p->remMsg(&rhs);
	}
	//��������
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);//���ø��Ե�swap����
	//����֮��Ѷ�Ӧ��folder��ӽ�ȥ
	for (auto p:lhs.folders)
	{
		p->addMsg(&lhs);
	} 
	for (auto p:rhs.folders){
		p->addMsg(&rhs);
	}
}

//��message��ӵ�ָ����Folder��
void Message::save(Folder &f){
	folders.insert(&f);//��f��ָ����ӵ�folders
	f.addMsg(this); 
} 
//��message��ָ����Folder��ȡ�� 
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
//��this��ӵ�m���ڵ�folders 
void Message::add_to_Folders(const Message &m){
	for (auto p:m.folders){
		p->addMsg(this);
	}
}
//��this�Ӱ������Folder��ȥ�� 
void Message::remove_from_Folders(){
	for (auto p:folders){
		p->remMsg(this);
	}
}

Message& Message::operator=(const Message &rhs){
	//ͨ����ɾ��ָ�룬�ٲ��������������Ը�ֵ��� 
	remove_from_Folders();//��this��folders��ȥ��������rhs�� 
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
Message::~Message(){
	remove_from_Folders();
	/*
	����remove_from_foldersȷ��û���κ�Folder������������
	��Messageָ�롣�������Զ�����string�����������ͷ�contents
	���Զ�����set�����������������ϳ�Աʹ�õ��ڴ� 
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
//Folder�Ŀ������캯��
Folder::Folder(const Folder &rhs){
	messages = rhs.messages;
	//����ָ��rhs��ҲҪָ�򿽱���this
	add_to_Message(rhs); 
}
Folder& Folder::operator=(const Folder &rhs){
	//�����Ը�ֵ
	remove_from_Message();
	messages = rhs.messages;
	add_to_Message(rhs);
	return *this;
}
Folder::~Folder(){
	remove_from_Message();//�������������ָ���ָ�롣set�����������ջء� 
}

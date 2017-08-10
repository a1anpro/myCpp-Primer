#include "Message.h"

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

void Folder::addMsg(Message *m){
	messages.insert(m);
}
void Folder::remMsg(Message *m){
	messages.erase(m);
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
	remove_from_Folder();
	/*
	����remove_from_foldersȷ��û���κ�Folder������������
	��Messageָ�롣�������Զ�����string�����������ͷ�contents
	���Զ�����set�����������������ϳ�Աʹ�õ��ڴ� 
	*/
}


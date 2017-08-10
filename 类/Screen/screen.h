#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
//#include "window_mgr.h"
using namespace std;

//class Window_mgr;
class Screen{
	//������֮�����Ԫ 
	friend class Window_mgr;//Window_mgr�ĳ�Ա���Է���Screen���˽�в��֡�
	//friend void Window_mgr::clear(ScreenIndex);//����ĳ�Ա��������Ϊ��Ԫ����
	 
public:
	typedef string::size_type pos;//�������ͳ�Ա
	//���캯�� 
	Screen() = default;//��Ϊ������Ĺ��캯�����������Ĭ�ϵĺ����Ǳ����
	Screen(pos ht, pos wd, char c=' '):height(ht), width(wd),contents(ht*wd, c){}//cursor�����ڳ�ʼֵΪ0
//############################################################################
	//��Ա����
	inline Screen &set(char);
	inline Screen &set(pos, pos, char); 
	
	char get()const{//��ȡ��괦���ַ� 
		return contents[cursor];} //��ʽ����
	inline char get(pos ht, pos wd) const;//��ʽ����
	Screen &move(pos r, pos c);//������֮�����ó����� 
	//��ʾ��Ļ���ݣ�//���ݶ����Ƿ���const���������Ǹ�����
	Screen &display(ostream &os){do_display(os);return *this;}
	const Screen &display(ostream &os) const{do_display(os);return *this;} 

	void some_member() const;//���Կɱ��Ա�� 
private://˽�г�Ա����	
	//�ú���������ʾ����
	void do_display(ostream &os)const{
		os << contents;//������� 
	} 
private:
	mutable size_t access_ctr = 0;//��һ��const������Ҳ���Ա��޸�.�ɱ��Ա�������أ��� 
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents; 
};

//��Ԫ�������ⲿ����
//void Window_mgr::clear(ScreenIndex); 


//inline��Ա����Ӧ������Ӧ���ඨ����ͬһ��ͷ�ļ��С�
//�趨ָ���ַ�
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;	//����굱ǰλ������Ϊc�ַ� 
	return *this;			//��this������Ϊ��ֵ���� 
}
inline Screen &Screen::set(pos r, pos col, char c)
{
	contents[r*width + col] = c;
	return *this;
}
 
inline Screen &Screen::move(pos r, pos c)//�����ں����Ķ��崦˵����������
{
	pos row = r * width;//�����е�λ��
	cursor = row + c;//�����ڽ�����ƶ���ָ������
	return *this; 	//����ֵ����ʽ���ض��� 
 } 
 
inline char Screen::get(pos r, pos c) const//������ڲ������������� 
 {
 	pos row = r * width;//�����е�λ�� 
	return contents[row+c];//���ظ����е��ַ�	
 }

#endif

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
//#include "window_mgr.h"
using namespace std;

//class Window_mgr;
class Screen{
	//声明类之间的友元 
	friend class Window_mgr;//Window_mgr的成员可以访问Screen类的私有部分。
	//friend void Window_mgr::clear(ScreenIndex);//将类的成员函数声明为友元函数
	 
public:
	typedef string::size_type pos;//定义类型成员
	//构造函数 
	Screen() = default;//因为有另外的构造函数，所以这个默认的函数是必须的
	Screen(pos ht, pos wd, char c=' '):height(ht), width(wd),contents(ht*wd, c){}//cursor的类内初始值为0
//############################################################################
	//成员函数
	inline Screen &set(char);
	inline Screen &set(pos, pos, char); 
	
	char get()const{//读取光标处的字符 
		return contents[cursor];} //隐式内联
	inline char get(pos ht, pos wd) const;//显式内联
	Screen &move(pos r, pos c);//可以在之后被设置成内联 
	//显示屏幕内容：//根据对象是否是const决定调用那个函数
	Screen &display(ostream &os){do_display(os);return *this;}
	const Screen &display(ostream &os) const{do_display(os);return *this;} 

	void some_member() const;//测试可变成员。 
private://私有成员函数	
	//该函数负责显示内容
	void do_display(ostream &os)const{
		os << contents;//输出内容 
	} 
private:
	mutable size_t access_ctr = 0;//在一个const对象中也可以被修改.可变成员（作用呢？） 
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents; 
};

//友元函数的外部声明
//void Window_mgr::clear(ScreenIndex); 


//inline成员函数应该与相应的类定义在同一个头文件中。
//设定指定字符
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;	//将光标当前位置设置为c字符 
	return *this;			//将this对象作为左值返回 
}
inline Screen &Screen::set(pos r, pos col, char c)
{
	contents[r*width + col] = c;
	return *this;
}
 
inline Screen &Screen::move(pos r, pos c)//可以在函数的定义处说明是内联的
{
	pos row = r * width;//计算行的位置
	cursor = row + c;//在行内将光标移动到指定的列
	return *this; 	//以左值的形式返回对象 
 } 
 
inline char Screen::get(pos r, pos c) const//在类的内部声明成内联的 
 {
 	pos row = r * width;//计算行的位置 
	return contents[row+c];//返回给定列的字符	
 }

#endif

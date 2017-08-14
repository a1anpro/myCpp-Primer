#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <iostream>
#include "screen.h"
#include <vector>
using namespace std;

class Window_mgr{
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = vector<Screen>::sizt_type;//

	//成员函数
	//#1-按照编号将指定的Screen置为空白
	void clear(ScreenIndex); 

private:
	//这个window_mgr追踪的Screen  //默认情况下 包含一个标准尺寸的空白Screen
	vector<Screen> screens{Screen(24,80,' ')};
};

//#1-按照编号将指定的Screen置为空白
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];//s是编号i的引用，指向我们想清空的那个屏幕 
	s.contents = string(s.height, s.width, ' ');//将原来的高和宽保留，将字符全部替换成空白 
}
#endif 

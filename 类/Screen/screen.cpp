#include <iostream>
using namespace std;
#include "screen.h"
#include "window_mgr.h"

void Screen::some_member()const{
	++access_ctr;//保存一个计数值，用于记录被调用的次数
	//其他工作 
}

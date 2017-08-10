#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <iostream>
#include "screen.h"
#include <vector>
using namespace std;

class Window_mgr{
public:
	//������ÿ����Ļ�ı��
	using ScreenIndex = vector<Screen>::sizt_type;//

	//��Ա����
	//#1-���ձ�Ž�ָ����Screen��Ϊ�հ�
	void clear(ScreenIndex); 

private:
	//���window_mgr׷�ٵ�Screen  //Ĭ������� ����һ����׼�ߴ�Ŀհ�Screen
	vector<Screen> screens{Screen(24,80,' ')};
};

//#1-���ձ�Ž�ָ����Screen��Ϊ�հ�
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];//s�Ǳ��i�����ã�ָ����������յ��Ǹ���Ļ 
	s.contents = string(s.height, s.width, ' ');//��ԭ���ĸߺͿ��������ַ�ȫ���滻�ɿհ� 
}
#endif 

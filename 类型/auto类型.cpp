#include <iostream>
using namespace std;

int main(){
	int i = 0, &r = i;//r��int���͵����ã���i
	auto a = r;//a��һ��������r��i�ı�������i��int
	
	const int ci = i, &cr = ci;//ci��һ��int������cr�ǳ������ã��󶨵���ci
	auto b = ci;//ci�Ƕ���const�����Ե�������b��int���͵���ͨ����
	auto c = cr;//c��һ��������cr������ci����ci�Ƕ���const
	auto d = &i;//i��������&i��ȡ��ַ������d��ָ��int��ָ�루���͵ĵ�ַ����ָ��������ָ�룩
	auto e = &ci;//e��ָ������������ָ�루ci�Գ���ȡ��ַ��һ�ֵײ�const��
	
	const auto f = ci;//f��const���͵�����
	auto &g = ci;//g�����ͳ��������ã��󶨵�ci
	const auto &j = 42;//����Ϊ��������ֱ�Ӱ�����ֵ
	
	a = 42;
	b = 42;
	c = 42;
	*d = 42;
	e = &ci;//e��ָ������������ָ�� 
	
	return 0;
} 

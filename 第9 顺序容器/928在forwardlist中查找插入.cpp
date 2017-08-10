#include <iostream>
#include <forward_list>
using namespace std;

void func(forward_list<string> &fli, const string& str1, const string &str2)
{
	//先查找再插入,如果找到就将str2差在后面，未找到就插在尾后
	auto beg = fli.begin();
	auto prev = fli.before_begin();//跟着一起走 
	bool find = false;
	while (beg != fli.end() && !find)
	{
		if (*beg==str1){
			//fli.insert_after(beg,str2);//插入
			fli.emplace_after(beg, str2);//两种方式是一样的。emplace的版本更快，没有做拷贝操作，直接新建。 
			find = true;//找到了就退出 
		}
		else
		{
			//没有找到就继续往后找
			++beg; 
		}
		++prev;
	} 
	//判断是否找到：找到了就直接退出，没找到就插到尾后
	if (!find)
	{
		fli.insert_after(prev,str2);//如果没有找到，现在prev保存的就是最后一个元素的迭代器。可以直接插到最后。
		//如果没有prev来保存就无法插入了 
	} 
}

int main(){
	forward_list<string> fli={"hello","yanhui","zhuxinyi"};
	string str1 = "yanhui";
	string str2 = "ajiao";
	
	func(fli,str1,str2);
	
	for (const auto &s : fli){
		cout << s<<endl;
	}
	
	return 0;
}

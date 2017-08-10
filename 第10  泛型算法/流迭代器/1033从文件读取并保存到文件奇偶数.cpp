#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

void func(const string &in_file, const string &odd_file, const string &even_file)
{
	ifstream istrm(in_file);
	ofstream odd_strm(odd_file), even_strm(even_file);//构建流 
	
	istream_iterator<int> in_iter(istrm), eof;//构造输入流的迭代器
	ostream_iterator<int> odd_iter(odd_strm, " "), even_iter(even_strm," "); 

	for_each(in_iter, eof, [&odd_iter, &even_iter](const int i){
		*(i&0x1?odd_iter:even_iter) = i;//决定用哪个迭代器 
	});//这个接受三个参数，前两个为输入范围，第三个为操作对象 
//	while (in_iter != eof){
//		if (*in_iter%2){
//			*odd_iter++ = *in_iter;
//		}
//		else{
//			*even_iter++ = *in_iter;
//		}
//		in_iter++;
//	}
}

int main(){
	func("int.txt", "odd.txt", "even.txt");
	
	return 0;
} 

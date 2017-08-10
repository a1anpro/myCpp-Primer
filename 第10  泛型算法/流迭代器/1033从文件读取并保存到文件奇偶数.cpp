#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

void func(const string &in_file, const string &odd_file, const string &even_file)
{
	ifstream istrm(in_file);
	ofstream odd_strm(odd_file), even_strm(even_file);//������ 
	
	istream_iterator<int> in_iter(istrm), eof;//�����������ĵ�����
	ostream_iterator<int> odd_iter(odd_strm, " "), even_iter(even_strm," "); 

	for_each(in_iter, eof, [&odd_iter, &even_iter](const int i){
		*(i&0x1?odd_iter:even_iter) = i;//�������ĸ������� 
	});//�����������������ǰ����Ϊ���뷶Χ��������Ϊ�������� 
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

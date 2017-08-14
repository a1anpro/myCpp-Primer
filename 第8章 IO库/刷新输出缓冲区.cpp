#include <iostream>
using namespace std;

int main(){
	cout << unitbuf;//设置ostream的cout对象，每次写操作之后都进行一次flush操作。而nounitbuf则是重置流。 
	cout << "hi" << endl;
	cout << "hi" << ends;//刷新缓冲区并且输出一个空格符 
	cout << "hi" << flush;//刷新不附加任何字符 
	return 0;
}

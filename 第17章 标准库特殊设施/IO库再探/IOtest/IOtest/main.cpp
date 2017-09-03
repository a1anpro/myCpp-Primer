#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {

	fstream inOut("IOfile.txt", fstream::ate | fstream::in | fstream::out);
	if (!inOut) {
		cout << "can not open the file" << endl;
	}

	auto end_mark = inOut.tellg();
	inOut.seekg(0, fstream::beg);
	size_t cnt = 0;
	string line;

	while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
		cnt += line.size() + 1;//1 presents newline
		auto mark = inOut.tellg();
		inOut.seekg(0, fstream::end);
		inOut << cnt;
		if (mark != end_mark) inOut << ' ';
		inOut.seekp(mark);
	}

	inOut.seekg(0, fstream::end);
	inOut << '\n';

	return 0;
}
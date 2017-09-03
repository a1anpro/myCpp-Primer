#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream outIn("IOfile.txt", fstream::in | fstream::out | fstream::ate);//lacate at the end of stream with in and out mode;
	
	if (!outIn){
		//if failed to open the file. return EXIT_FAILURE
		cout << "file can not be opened"<<endl;
		return EXIT_FAILURE;
	}
	
	//if open file successfully
	auto end_mark = outIn.tellg();//mark end position of the current stream;
	outIn.seekg(0, fstream::beg);//after mark the end pos, we the the flag to the begin of stream;
	size_t cnt = 0;//count how many bytes
	string str;//read from ifstream

	while (outIn && outIn.tellg() != end_mark && getline(outIn, str)){
		//while outIn stream is valid and flag not turn end.
		cnt += str.size() + 1;
		auto mark = outIn.tellg();//mark the current position and we will return later;
		outIn.seekp(0, fstream::end);//turn to the end of stream and write cnt behind it;
		outIn << cnt;
		if (mark != end_mark){
			//if this pos is not end of origin text, write a space behind
			outIn << ' ';
		}
		outIn.seekg(mark);//return to the marked position and continue read from it;
	}
	outIn.seekp(0, fstream::end);
	outIn << '\n';
	return 0;
}

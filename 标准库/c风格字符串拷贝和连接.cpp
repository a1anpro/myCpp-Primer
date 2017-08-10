#include <iostream>
using namespace std;
#include <cstring>

int main(){
	const char cstr1[]="hello,world";
	const char cstr2[]="hello,kitty";

	constexpr size_t new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) + 1;
	char cstr3[new_size];
	
	strcpy(cstr3, cstr1);
	strcat(cstr3, " ");
	strcat(cstr3, cstr2);
	
	cout << cstr3 <<endl;
	
	return 0;
}

#include <iostream>
using namespace std;
#include "Message.h"

int main(){
	Message firstMail("hello");
	Message signInMail("welcome to CppPrimer");
	Folder mailBox;
	
	firstMail.print_debug();
	firstMail.save(mailBox);
	mailBox.print_debug();
	
	firstMail = firstMail;//test for assignment to self
	firstMail.print_debug();
	mailBox.print_debug();
	
	return 0;
}

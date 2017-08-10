#include <iostream>
#include "StrBlobPtr.h"
using namespace std;

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}

#include <iostream>
#include "ConstStrBlobPtr.h"
using namespace std;

ConstStrBlobPtr StrBlob::begin() const{
	return ConstStrBlobPtr(*this);
} 
ConstStrBlobPtr StrBlob::end() const{
	return ConstStrBlobPtr(*this, data->size());
}

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> *vi){
	for (const auto i: *vi){
		cout << i << " ";
	}
	delete vi;
	vi = nullptr;
}

vector<int> *input(vector<int> *vi){
	int i;
	while (cin >> i){
		(*vi).push_back(i);
	}
	
	return vi;
}

vector<int> *get(){
	return new vector<int>;
}

void func(){
	print(input(get()));
}

int main(){
	func();
	return 0;
}

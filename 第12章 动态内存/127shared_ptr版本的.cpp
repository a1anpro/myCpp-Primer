#include <iostream>
#include <memory>
using namespace std;
#include <vector>
using vi = vector<int>;
using namespace std;

void print(shared_ptr<vi> shared){
	for (const auto &i : (*shared)){
		cout << i << " ";
	}
}

shared_ptr<vi> input(shared_ptr<vi> shared)
{
	int i;
	while (cin >> i){
		(*shared).push_back(i);
	}
	return shared;
}

shared_ptr<vi> get(){
	return make_shared<vi>();
}

void func(){
	print(input(get()));
}

int main(){
	func();
	
	return 0;
}

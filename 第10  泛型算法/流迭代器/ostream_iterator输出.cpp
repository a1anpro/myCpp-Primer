#include <iostream>
using namespace std;
#include <iterator>
#include <vector>

int main(){
	vector<int> vi={1,2,3,4,5};
	ostream_iterator<int> out_iter(cout, " ");
	
	for (auto i:vi){
		*out_iter++ = i;//�ȼ���out_iter=i; 
	}
	
	//����д��
	copy(vi.begin(), vi.end(), out_iter);//��vi��begin��end������out_iter
	 
	return 0;
} 

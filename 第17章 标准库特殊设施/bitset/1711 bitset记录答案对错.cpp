#include <iostream>
#include <bitset>
using namespace std;

//用位来标识一份答卷的对错.类应该包含bitset<>，它需要一个大小，这个大小应该是用户给的
using size = size_t;

template<size N>
class QuizResult;
template<size N> ostream& operator<<(ostream &, const QuizResult<N>&);

template<size N>
class QuizResult{
	friend ostream& operator<<<N>(ostream &os, const QuizResult<N> &qr);//一对一友好关系的应用p589！！！ 

public:
	QuizResult() = default;
	QuizResult(const string &s):bv(s){}//用s来初始化bv，s中必须是1010的字符
	
	void update(size pos, bool ans){
		bv.set(pos, ans);
	}
	
	double grade(const QuizResult<N> &correct){
		//返回分数：将bv和correct进行^操作，相同位=0，相异位=1
		return (bv ^ correct.bv).flip().count() * 1.0 / bv.size() * 100;		 
	}
	
private:
	bitset<N> bv;//保存对应的值 
}; 

template<size N>
ostream& operator<<(ostream &os, const QuizResult<N> &qr){
	os << qr.bv;
	return os;
}

int main(){
	QuizResult<10>  qr("1010101111");
	QuizResult<10> ans("1010101010"); 
//	cout << qr<<endl;
	cout << qr.grade(ans) <<endl;
	return 0;
} 

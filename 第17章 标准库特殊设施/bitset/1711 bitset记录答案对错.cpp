#include <iostream>
#include <bitset>
using namespace std;

//��λ����ʶһ�ݴ��ĶԴ�.��Ӧ�ð���bitset<>������Ҫһ����С�������СӦ�����û�����
using size = size_t;

template<size N>
class QuizResult;
template<size N> ostream& operator<<(ostream &, const QuizResult<N>&);

template<size N>
class QuizResult{
	friend ostream& operator<<<N>(ostream &os, const QuizResult<N> &qr);//һ��һ�Ѻù�ϵ��Ӧ��p589������ 

public:
	QuizResult() = default;
	QuizResult(const string &s):bv(s){}//��s����ʼ��bv��s�б�����1010���ַ�
	
	void update(size pos, bool ans){
		bv.set(pos, ans);
	}
	
	double grade(const QuizResult<N> &correct){
		//���ط�������bv��correct����^��������ͬλ=0������λ=1
		return (bv ^ correct.bv).flip().count() * 1.0 / bv.size() * 100;		 
	}
	
private:
	bitset<N> bv;//�����Ӧ��ֵ 
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

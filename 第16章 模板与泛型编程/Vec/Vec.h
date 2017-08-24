#pragma once

#include <iostream>
#include <initializer_list>
#include <memory>
#include <utility>//pair�����У�����Ϊ������;��ͷ�ļ�
 
using namespace std;

template<typename T>
class Vec{
public:
	typedef size_t size_type;//�����Լ���size_type 
	//���캯�� 
	Vec():curr(nullptr), first_free(nullptr), cap(nullptr){}
	Vec(initializer_list<T> il);//��Ҫ�ں������ڹ��� 
	//�������ƺ���
	Vec(const Vec &);//�������캯��
	Vec& operator=(const Vec &);//������ֵ����
	~Vec();//�������� 
	//�ƶ����ƺ���
	Vec(Vec &&) noexcept;
	Vec& operator=(Vec &&)noexcept;

	//��ͨ��Ա����	
	bool empty() const{
		//��������ֻ�ܵ��ó�����Ա����
		return size() == 0; 
	}
	const size_type size() const{
		return first_free - curr;
	}
	const size_type capacity() const{
		return cap - curr;
	}
	T* begin(){
		return curr;
	}
	T* end(){
		return first_free;
	}
	const T* cbegin() const{
		return curr;
	}
	const T* cend() const{
		return first_free;
	}
	
	//���롢ɾ������
	void push_back(const T &);
	T pop_back(); 
	
	template<typename...Args>
	void emplace_back(Args&&...args)//��չģ���������ģʽ��&&��ÿ������������ֵ����
	{
		chk_n_alloc();//�ȼ���Ƿ��ж���ռ�
		//����
		alloc.construct(first_free++, forward<Args>(args)...);//����չ��ģ�������������չ�˺�������������ÿ��������Ҫ�������� 
	} 
	
	//����Ԫ�ز���
	T& operator[](size_type i); 
	
private://˽�еĹ����࣬�����Ÿ������
	static allocator<T> alloc;//�����ڴ�ľ�̬����,���� 
	//�����кܶ��Ա��������ͬ�Ĳ�������������ֵ�����١����ڿ����͸�ֵ֮ǰ����Ҫ������Ӧ�ļ�飬���԰���Щ���ϸ�ڶ��������
	
	//�����ڴ棬������һ��������Χ��Ԫ��,���ص���һ������pair 
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	
	//����Ƿ��пռ�����һ����Ԫ�صĿռ䣬���û�пռ䣬�����reallocate�������ڴ�
	void chk_n_alloc(){
		if (size() == capacity()){
			reallocate();
		}
	} 
	
	//��ø����ڴ沢���������ƶ����µĿռ䣬�Ա����push����Ԫ�� 
	void reallocate();
	
	//����Ԫ�أ����ͷ��ڴ� 
	void free();
private:
	//��Ԫ��ָ�룬��ЧԪ��βָ�룬����ռ�βָ��
	T *curr;
	T *first_free;
	T *cap;
};
//���徲̬��allocator 
template<typename T>
allocator<T> Vec<T>::alloc;

//���ߺ������ȶ��壺
template<typename T> 
pair<T*, T*> Vec<T>::alloc_n_copy(const T* first, const T* last){
	//����allocate���䣬����construct����
	auto data = alloc.allocate(last - first);
	return {data, uninitialized_copy(first, last, data)};//��ʽ�ع�����pair. uninitialized_copy()���ع�����βָ�� 
}

//���·���ռ䣬�����ǣ���ԭ���Ŀռ��С�Ϸ������������ԭ���ռ�Ϊ0�������1 
template<typename T>
void Vec<T>::reallocate(){
	auto newSize = size()?2*size():1;
	auto newData = alloc.allocate(newSize);
	
	//��curr��first_free ��Ԫ��һ��һ������/�ƶ����µĿռ���
	auto dst = newData;//Ҫ����data������curr...dst means destination
	for (size_type i = 0; i != size(); ++i){
		alloc.construct(dst++, move(*curr++));//move curr�����ݣ���Ϊcurrֻ��Ҫһ���û� 
	} 
	curr = newData;
	first_free = dst;//dst�ƶ����β���ˡ� 
	cap = newData + newSize;
}

template<typename T> 
void Vec<T>::free(){
	//���ٳ�Ա���ͷ��ڴ�
	if (curr){
		for (auto p = first_free; p != curr;){
			alloc.destroy(--p);
		}
		alloc.deallocate(curr, cap - curr);//reallocate��ָ�벻��Ϊ�գ����ҵڶ����ռ���������ʱ��Ĵ�С��һ���ġ� 
	}
	//Ҳ������for_each��lambda���ʽ�������٣�for_each�ǽ����õģ�����Ҫȡ��ַ 
}

//�ⲿ����Ĺ��캯�� 
template<typename T>
Vec<T>::Vec(initializer_list<T> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	curr = data.first;
	first_free = cap = data.second;
}

//��Ա������
//�������ƺ���
template<typename T> 
Vec<T>::Vec(const Vec &rhs){
	cout << "copy construction"<<endl;
	 auto data = alloc_n_copy(rhs.curr, rhs.first_free);
	 curr = data.first;
	 first_free = cap = data.second;
}
template<typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs){//����Vec�Ѿ�������������
	//�������ڴ棬����Ԫ�أ�����ԭ����
	cout << "copy assignment"<<endl; 
	auto data = alloc_n_copy(rhs.curr, rhs.first_free);
	free();//�ͷ�ԭ�����ڴ�
	curr = data.first;
	first_free = cap = data.second;
	return *this;
}
template<typename T>
Vec<T>::~Vec(){
	free(); 
}

//�ƶ����� 
template<typename T>
Vec<T>::Vec(Vec &&rhs)noexcept
	:curr(rhs.curr), first_free(rhs.first_free), cap(rhs.cap)
{
	cout << "move construction"<<endl;
	rhs.curr = rhs.first_free = rhs.cap = nullptr;
}
template<typename T>
Vec<T>& Vec<T>::operator=(Vec &&r)noexcept{
	//����Ƿ����Ը�ֵ
	cout << "move assignment"<<endl;
	if (this != &r){
		curr = r.curr;
		first_free = r.first_free;
		cap = r.cap;
		r.curr = r.first_free = r.cap = nullptr;
	} 
	return *this;
}

//���롢ɾ������ 
template<typename T>
void Vec<T>::push_back(const T &value){
	chk_n_alloc();//�ȼ��ռ�
	alloc.construct(first_free, value);//��value������first_freeλ�õ�Ԫ��
	first_free++; 
}
template<typename T>
T Vec<T>::pop_back(){
	//�����pop��������һ������Ϊ�գ���������ǵ����齻���û��Ϳ�����
	--first_free;
	auto ret = *first_free;
	alloc.destroy(first_free);
	return ret; 
}

//���ʲ���
template<typename T>
T& Vec<T>::operator[](size_type i){
	return *(curr + i);
} 








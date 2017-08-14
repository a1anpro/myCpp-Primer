#include "StrVec.h"

allocator<string> StrVec::alloc;//��.h������������Ҫ��cpp�ж��� 
//�ڲ����ߺ��� 
pair<string*,string*> StrVec::alloc_n_copy(const string *beg, const string *end){
	auto data = alloc.allocate(end-beg);//allocate(n)����n��ԭʼ��δ������ڴ� 
	return {data, uninitialized_copy(beg,end,data)}; 
}
//void StrVec::free(){
//	//���ܸ�deallocateһ����ָ�룬���elementsΪ0����ʲô������
//	if (elements){
//		for (auto p = first_free; p!=elements;){
//			alloc.destroy(--p);
//		}
//		alloc.deallocate(elements, cap-elements);
//	}
//}

void StrVec::free(){
	//��for_each��lambda������������
	auto beg = elements;
	for_each(elements, first_free,[this](string &rhs){
		alloc.destroy(&rhs);//for_each����Է�Χ�ڵ�Ԫ�ض������õ��ˡ�������&�ָ���ַ 
	});
	alloc.deallocate(beg, cap-beg);//Ҫ�����ͷ��ڴ� 
}

void StrVec::reallocate(){
	//��Ϊ����Ҫ��ԭ���ڴ��Ԫ�طŵ������¿��ٵ��ڴ��У�Ҫ��string���п���������
	//����̫���������ƶ�����
	auto newCapacity = size()?size()*2:1;//���sizeΪ0�Ļ������¿�һ��
	//�����µ��ڴ档����û�й��� 
	auto newData = alloc.allocate(newCapacity);
	//�����ݴӾ��ڴ��ƶ����µ��ڴ�
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest, move(*elem++));//��move����string�����ÿ������� 
	}
	//�����ñ�׼����㷨���ƶ�������������ѭ��
	//auto last = uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),elem); 
	free();//һ�������ƶ�����Ԫ�أ����ͷžɵ��ڴ�ռ�
	elements = newData;
	first_free = dest;//construct��������ЧԪ�ص���һλ
	cap = elements + newCapacity; 
}

//���캯��
StrVec::StrVec(initializer_list<string> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
} 

//�������ƺ��� 
StrVec::StrVec(const StrVec &rhs){
	//��rhs��ֵ������this��Ҫ��Ԫ�ض�������ȥ������operator=Ҳ���������������Ҫ�����ڲ����ߺ���
	auto data = alloc_n_copy(elements, first_free);
	elements = data.first;
	first_free = cap = data.second;
}
StrVec& StrVec::operator=(const StrVec &rhs){
	//Ҫ������ֵ�Ļ����ȱ���ԭ���ģ������� 
	auto data = alloc_n_copy(elements, first_free);
	free();
	elements = data.first;
	first_free = cap = data.second;
	
	return *this;
}
StrVec::~StrVec(){
	free();
}

//�ƶ���ֵ�����
StrVec& StrVec::operator=(StrVec &&s) noexcept{
	if (this != &s){
		free();//���ͷ�thisԭ�����ڴ� 
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
} 

//��Ա������ʵ��

//��������newCap�ռ���ڴ�
void StrVec::reserve(size_t newCap){
	if (newCap <= capacity()){
		return ;//����Ҫ���·��� 
	}
	alloc_to_move(newCap);//����ռ䣬���Ұ�Ԫ���ƶ����µĿռ� 
}
void StrVec::resize(size_t newCap, const string &str){//��������ʱ���Ĭ��ֵ�Ϳ����ˡ���һ����������ʱ��ֻ�ܸ�û��Ĭ�ϵ���� 
	//���newCapС��size()����ضϣ����ͷ��ڴ�
	if (newCap < size()){
		while (first_free != newCap + elements){
			alloc.destroy(--first_free);
		}
	}
	//���newCap����size() ���·���
	 else if (newCap > size())
	 {
		if (newCap > capacity()){
			reserve(2*newCap);
		}
		for (size_t i = size(); i!=newCap; ++i){
			alloc.construct(first_free++, str);
		}
	 }
} 
void StrVec::alloc_to_move(size_t newCap){
	//�����µĿռ�
	auto newData = alloc.allocate(newCap);//����� 
	auto dest = newData;//Ŀ��
	auto elem = elements;//Դ
	for (size_t i = size(); i!=size(); ++i){
		alloc.construct(dest,move(*elem++));//��move���ƶ����죬�����ǿ������졣Ч�ʸ��� 
	}
	free();//�ͷ�ԭ�����ڴ棬��ָ��ָ���µ��ڴ�
	elements = newData;
	first_free = dest;//�ƶ��������һ����ЧԪ�ص���һλ
	cap = elements + newCap; 
}

void StrVec::push_back(const string &str){
	//����chk_n_allocate��ȷ��push��ʱ��һ���пռ�
	chk_n_alloc();//�������ص�ʱ��pushһ���пռ�
	
	//��first_free����string
	alloc.construct(first_free++, str);//����alloc��construct������str 
} 



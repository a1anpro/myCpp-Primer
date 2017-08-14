#include "StrVec.h"

allocator<string> StrVec::alloc;//在.h中声明，还需要在cpp中定义 
//内部工具函数 
pair<string*,string*> StrVec::alloc_n_copy(const string *beg, const string *end){
	auto data = alloc.allocate(end-beg);//allocate(n)分配n个原始的未构造的内存 
	return {data, uninitialized_copy(beg,end,data)}; 
}
//void StrVec::free(){
//	//不能给deallocate一个空指针，如果elements为0，则什么都不做
//	if (elements){
//		for (auto p = first_free; p!=elements;){
//			alloc.destroy(--p);
//		}
//		alloc.deallocate(elements, cap-elements);
//	}
//}

void StrVec::free(){
	//用for_each和lambda函数来做销毁
	auto beg = elements;
	for_each(elements, first_free,[this](string &rhs){
		alloc.destroy(&rhs);//for_each是针对范围内的元素都解引用的了。必须用&恢复地址 
	});
	alloc.deallocate(beg, cap-beg);//要调用释放内存 
}

void StrVec::reallocate(){
	//因为我们要将原来内存的元素放到现在新开辟的内存中，要对string进行拷贝再析构
	//代价太大，我们用移动构造
	auto newCapacity = size()?size()*2:1;//如果size为0的话，就新开一个
	//分配新的内存。但是没有构造 
	auto newData = alloc.allocate(newCapacity);
	//将数据从旧内存移动到新的内存
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest, move(*elem++));//用move构造string，不用拷贝构造 
	}
	//可以用标准库的算法和移动迭代器来代替循环
	//auto last = uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),elem); 
	free();//一旦我们移动完了元素，就释放旧的内存空间
	elements = newData;
	first_free = dest;//construct完后就在有效元素的下一位
	cap = elements + newCapacity; 
}

//构造函数
StrVec::StrVec(initializer_list<string> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
} 

//拷贝控制函数 
StrVec::StrVec(const StrVec &rhs){
	//把rhs的值拷贝到this，要把元素都拷贝过去。并且operator=也有这个操作。我们要做个内部工具函数
	auto data = alloc_n_copy(elements, first_free);
	elements = data.first;
	first_free = cap = data.second;
}
StrVec& StrVec::operator=(const StrVec &rhs){
	//要拷贝赋值的话，先保存原来的，再销毁 
	auto data = alloc_n_copy(elements, first_free);
	free();
	elements = data.first;
	first_free = cap = data.second;
	
	return *this;
}
StrVec::~StrVec(){
	free();
}

//移动赋值运算符
StrVec& StrVec::operator=(StrVec &&s) noexcept{
	if (this != &s){
		free();//先释放this原来的内存 
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
} 

//成员函数的实现

//分配容纳newCap空间的内存
void StrVec::reserve(size_t newCap){
	if (newCap <= capacity()){
		return ;//不需要重新分配 
	}
	alloc_to_move(newCap);//分配空间，并且把元素移动到新的空间 
}
void StrVec::resize(size_t newCap, const string &str){//在声明的时候给默认值就可以了。下一次再声明的时候只能给没有默认的添加 
	//如果newCap小于size()，则截断，并释放内存
	if (newCap < size()){
		while (first_free != newCap + elements){
			alloc.destroy(--first_free);
		}
	}
	//如果newCap大于size() 就新分配
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
	//分配新的空间
	auto newData = alloc.allocate(newCap);//存起点 
	auto dest = newData;//目标
	auto elem = elements;//源
	for (size_t i = size(); i!=size(); ++i){
		alloc.construct(dest,move(*elem++));//用move来移动构造，而不是拷贝构造。效率更高 
	}
	free();//释放原来的内存，将指针指向新的内存
	elements = newData;
	first_free = dest;//移动到了最后一个有效元素的下一位
	cap = elements + newCap; 
}

void StrVec::push_back(const string &str){
	//调用chk_n_allocate来确保push的时候一定有空间
	chk_n_alloc();//当它返回的时候，push一定有空间
	
	//在first_free构造string
	alloc.construct(first_free++, str);//调用alloc的construct来构造str 
} 



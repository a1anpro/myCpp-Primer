# 为什么vector不能存引用？

标签（空格分隔）： c++/reference    CN-5th/C++11

---

遇到了这样一段代码：编译器却报错
```cpp
template<typename T>
void f(T &&t){
	vector<T> v;
}
int main(){
	int a = 10;
	f(a);
	return 0;
}
```

a是一个左值，当左值传递给模板参数是右值的模板函数时，T被推断为T&,也就是说T是int&。那么为什么vector容器不能存引用呢？
答：容器的元素必须是可以分配空间的元素，而引用是在初始化的时候绑定在变量上的，而且不能让它们引用到别的对象上去。同理可得：const int类型的变量（即not-assignable的变量）都不能放在此类容器中的。

reference to:[discuss in SO](https://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references)

# 为什么vector不能存引用？

标签（空格分隔）： c++/reference    CN-5th

---

遇到了这样一段代码：
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





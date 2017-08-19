#ifndef IMAGE_H
#define IMAGE_H

static const float PI = 3.14159f;

//抽象基类 
class Shape{
public:
	Shape() = default;
	//虚函数
	//返回图形名字 
	virtual string shape_name() const = 0;
	virtual void resize_by_percentage(float pct) const = 0;
	virtual ~Shape(){}
};
//派生类，抽象类
class Shape_2D:public Shape{
public:
	Shape_2D() = default;
	Shape_2D(float x, float y):_x(x), _y(y){}

	virtual float area() const = 0;
	virtual float diameter() const = 0;
	virtual float circumference() const = 0;
	
	virtual ~Shape_2D() override{} //给让析构函数成为虚函数是为了：在基类指针指向派生类对象，释放该指针的时候，调用派生类对象的析构函数。 

protected:
	float _x = 0.0f;
	float _y = 0.0f;
}; 

class Shape_3D:public Shape{
public:
	Shape_3D() = default;
	Shape_3D(float x, float y):_x(x), _y(y), _z(z){}

	virtual float volume() const = 0;
	
	virtual ~Shape_3D() override{}

protected:
	float _x = 0.0f;
	float _y = 0.0f;
	float _z = 0.0f;
}; 

class Circle:public Shape_2D{
public:
	Circle()=default;
	explicit Circle(float radius):_radius(radius){}
	Circle(float center_x, float center_y, float radius)
		:Shape_2D(center_x, center_y), _radius(radius){}
	
	string shape_name() const override {return "i'm circle";}
	void resize_by_percentage(float pct) const override {_radius *= pct;}
	float area() const override {return PI * _radius * _radius;}
	float diameter() const override {return 2 * _radius;}
	float circumference() const override {return 2 * PI * _radius;}
	
	virtual ~Circle override {}
protected:
	float _radius = 1.0f;//默认初始化是单位1 
};

class Box:public Shape_3D{
public:
	Box() = default;
	explicit Box(float width) : half_len_x(0.5*width), half_len_y(0.5*width), half_len_z(0.5*width){}
	Box(float center_x, float center_y, float center_z, float len_x, float len_y, float len_z)
		:Shape_3D(center_x, center_y, center_z),half_len_x(0.5*len_x), half_len_y(0.5*len_y), half_len_z(0.5*len_z){}
	
	string shape_name() const override {return "i'm box";}
	void resize_by_percentage(float pct) const override {half_len_x *= pct; half_len_y *= pct; half_len_z *= pct;}
	float volume() const override{ return half_len_x * half_len_y * half_len_z * 8;} 
	
protected:
	float half_len_x = 0.5f;
	float half_len_y = 0.5f;
	float half_len_z = 0.5f;
};

#endif 


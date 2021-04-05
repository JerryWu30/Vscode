#include <iostream>
#include <cmath>

using namespace std;

class Shape //基类
{
public:
    virtual double area()  = 0;     //定于纯虚函数，因为需要实现多态
};

class Circle:public Shape
{
    public:
Circle(double r):radius(r){}                                     //结构函数
  virtual double area()  {return 3.141592653*radius*radius;};   
 protected:
  double radius;                                              
};

//矩形类
class Rectangle:public Shape
{
    public:
 Rectangle(double w,double h):width(w),height(h){}               //结构函数
 virtual double area()  {return width*height;}             
 protected:
  double width,height;                                         
};

//三角形类
class Triangle:public Shape
{
    public:
        Triangle(double a,double b,double c):length_a(a),length_b(b),length_c(c) {}                
        virtual double area()  {
            s=(length_a+length_b+length_c)/2;
            return sqrt(s*(s-length_a)*(s-length_b)*(s-length_c));
            }          
    protected:
        double length_a,length_b,length_c,s;                                  
};    
//类外的函数，类对象作为参数值
void printArea( Shape &s) //将对象引用作为参数，注意需要加上&符号表示应用。
{cout<<s.area()<<endl;}                                            //输出s的面积

int main()
{
 Circle circle(30.1);                                      
 cout<<"Area of Circle    =";         
 printArea(circle);                                     
 Rectangle rectangle(1.7,9.5);                              
 cout<<"Area of Rectangle =";                                    
 printArea(rectangle);                                    
 Triangle triangle(6,8,10);                           
 cout<<"Area of Triangle  =";
 printArea(triangle);         
 system("pause");
 return 0;
}


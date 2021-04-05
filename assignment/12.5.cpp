#include <iostream>
#include <cmath>
using namespace std;
//基类
class Shape
{
    public:
        virtual double area() =0;                               
};

class Circle:public Shape //继承
{
    public:
        Circle(double r):radius(r){}                                     
        virtual double area()  {return 3.141592653*radius*radius;};   
    protected:
        double radius;                                                
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

//正方形类
class Square:public Shape
{
    public:
        Square(double s):side(s){}                                      
        virtual double area()  {return side*side;}              
    protected:
         double side;
};

//矩形类
class Rectangle:public Shape
{
    public:
        Rectangle(double w,double h):width(w),height(h){}              
        virtual double area()  {return width*height;}           
    protected:
        double width,height;                                        
};                                              

//梯形类
class Trapezoid:public Shape
{
    public:
        Trapezoid(double t,double b,double h):top(t),bottom(t),height(h){} 
        virtual double area()  {return 0.5*(top+bottom)*height;}     
    protected:
        double top,bottom,height;                                          
};
                                                                      //基本和12.4题类似

int main()
{
 Circle circle(1.1);                                             
 Square square(2.2);                                              
 Rectangle rectangle(3.3,4.4);                                 
 Trapezoid trapezoid(5.5,6.6,7.7);                                
 Triangle triangle(8.8,9.9,11.11);                                   
 Shape *pt[]={&circle,&square,&rectangle,&trapezoid,&triangle}; 
                                //基类指针数组，注意使用引用符号
 double areas=0.0;                                                //areas为总面积
 for(int i=0;i<5;i++)        
  {areas=areas+pt[i]->area();}    //利用->访问对象的成员
 cout<<"Total Area="<<areas<<endl;   //输出总面积
 system("pause");
 return 0;
}



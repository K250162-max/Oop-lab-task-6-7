#include <iostream>
#include <cmath>
using namespace std;

class Shape{
protected:
    int x,y;
    string color;
    float borderThickness;
public:
    Shape(int x,int y,string c,float b=0){
        this->x=x;
        this->y=y;
        color=c;
        borderThickness=b;
    }
    virtual void draw(){
        cout<<"Drawing Shape"<<endl;
    }
    virtual double calculateArea(){
        return 0;
    }
    virtual double calculatePerimeter(){
        return 0;
    }
};

class Circle:public Shape{
    double radius;
public:
    Circle(int x,int y,string c,float b,double r):Shape(x,y,c,b){
        radius=r;
    }
    void draw(){
        cout<<"Drawing Circle"<<endl;
    }
    double calculateArea(){
        return 3.1416*radius*radius;
    }
    double calculatePerimeter(){
        return 2*3.1416*radius;
    }
};

class Rectangle:public Shape{
    double width,height;
public:
    Rectangle(int x,int y,string c,float b,double w,double h):Shape(x,y,c,b){
        width=w;
        height=h;
    }
    void draw(){
        cout<<"Drawing Rectangle"<<endl;
    }
    double calculateArea(){
        return width*height;
    }
    double calculatePerimeter(){
        return 2*(width+height);
    }
};

class Triangle:public Shape{
    double a,b,c;
public:
    Triangle(int x,int y,string col,float bt,double a,double b,double c):Shape(x,y,col,bt){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    void draw(){
        cout<<"Drawing Triangle"<<endl;
    }
    double calculatePerimeter(){
        return a+b+c;
    }
    double calculateArea(){
        double s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};

class Polygon:public Shape{
    int sides;
    double length;
public:
    Polygon(int x,int y,string c,float b,int s,double l):Shape(x,y,c,b){
        sides=s;
        length=l;
    }
    void draw(){
        cout<<"Drawing Polygon"<<endl;
    }
    double calculatePerimeter(){
        return sides*length;
    }
    double calculateArea(){
        return 0;
    }
};

int main(){
    Circle c(0,0,"Red",1,5);
    Rectangle r(1,1,"Blue",1,4,6);
    Triangle t(2,2,"Green",1,3,4,5);
    Polygon p(3,3,"Yellow",1,5,4);

    c.draw();
    cout<<c.calculateArea()<<" "<<c.calculatePerimeter()<<endl;

    r.draw();
    cout<<r.calculateArea()<<" "<<r.calculatePerimeter()<<endl;

    t.draw();
    cout<<t.calculateArea()<<" "<<t.calculatePerimeter()<<endl;

    p.draw();
    cout<<p.calculateArea()<<" "<<p.calculatePerimeter()<<endl;

    return 0;
}

#include <iostream>
using namespace std;

class MyColor
{
    protected:
       int color;
    public:
       MyColor();
       ~MyColor();
       void input();
       void display();
};
MyColor::MyColor()
{
    this->color = 0;
}
MyColor::~MyColor()
{

}
void MyColor::input()
{
    cout<<"Enter color: "<<endl;
    cin>>color;
}
void MyColor::display()
{
    cout<<"Color is: "<<color<<endl;
}
class Point
{
    private:
        float x, y, z;
    public:
        Point();
        ~Point();
        void input();
        float translating(float dx, float dy);
        void display();
};
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::~Point()
{

}
void Point::input()
{
    float X, Y;
    cout<<"Enter x: "<<endl;
    cin>>x;
    cout<<"Enter y: "<<endl;
    cin>>y;
    cout<<"Enter dx, dy: "<<endl;
    cin>>X>>Y;
    z = translating(X, Y);
}
float Point::translating(float dx, float dy)
{
    return this->x+dx, this->y+dy;
}
void Point::display()
{
    cout<<"X and Y in plane: "<<z<<endl;
}
class Triangle : public MyColor
{
    private:
        float A, B, C;
        float a, a1, b, b1, c, c1;
    public:
        Triangle();
        Triangle(float X, float Y, float Z, int k);
        ~Triangle();
        float moveX(float X, float dx);
        float moveY(float X, float dy);
        void input();
        void display();
};
Triangle::Triangle()
{
    this->A = this->B = this->C = 0;
    this->color = 0;
}
Triangle::Triangle(float X, float Y, float Z, int k)
{
    this->A = X;
    this->B = Y;
    this->C = Z;
    this->color = k;
}
Triangle::~Triangle()
{

}
float Triangle::moveX(float X, float dx)
{
    return (X + dx);
}
float Triangle::moveY(float X, float dy)
{
    return (X + dy);
}
void Triangle::input()
{
    float x, y;
    MyColor::input();
    cout<<"Enter dx, dy:"<<endl;
    cin>>x>>y;
    cout<<"Enter A: "<<endl;
    cin>>A;
    a = moveX(A,x);
    a1 = moveY(A, y);
    cout<<"Enter B: "<<endl;
    cin>>B;
    b = moveX(B,x);
    b1 = moveY(B,y);
    cout<<"Enter C: "<<endl;
    cin>>C;
    c = moveX(C,x);
    c1 = moveY(C,y);
}
void Triangle::display()
{
    cout<<"A is: "<<a<<" , "<<a1<<endl;
    cout<<"B is: "<<b<<" , "<<b1<<endl;
    cout<<"C is: "<<c<<" , "<<c1<<endl;
    MyColor::display(); 
}
int main()
{
    Triangle a;
    a.input();
    cout<<"Sau khi tinh tien: "<<endl;
    a.display();
    system("pause");
}
#include <iostream>
#include <cmath>
using namespace std;

class MyColor
{
    private:
        int color;
    public:
        void input();
        void display();
};
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
        float x, y;
    public:
        void input();
        void display();
};
void Point::input()
{
    cout<<"Enter x, y: "<<endl;
    cin>>x>>y;
}

void Point::display()
{
    cout<<"X and Y in plane: "<<x<<" , "<<y<<endl;
}
class Line : public MyColor
{
    private:
        Point p;
        float A, B;
    public:
        void input();
        friend double range(Line p1, Line p2);
        void display();
};
void Line::input()
{
    MyColor::input();
    p.input();
    cout<<"Enter A: "<<endl; cin>>A;
    cout<<"Enter B: "<<endl; cin>>B;
}
double range(Line p1, Line p2)
{
    double kc;
	kc=sqrt(double(p1.A-p2.A)*(p1.A-p2.A)+(p1.B-p2.B)*(p1.B-p2.B));
	return kc;
}
void Line::display()
{
    MyColor::display();
    p.display();
    cout<<"A and B is: "<< A<<" , "<<B<<endl;
}
int main()
{
    Line line1, line2;
    cout<<"Enter line 1:"<<endl;
    line1.input();
    cout<<"Enter line 2:"<<endl;
    line2.input();
    cout<<"Display line 1:"<<endl;
    line1.display();
    cout<<"Display line 2:"<<endl;
    line2.display();
    double z = range(line1, line2);
    cout<<"Range between two point: " << z <<endl;
    system("pause");
}
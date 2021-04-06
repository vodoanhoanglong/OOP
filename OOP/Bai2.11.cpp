#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define PI 3.14
class MyColor
{
protected:
    string colorID;

public:
    MyColor();
    void set();
    void displayColor();
    ~MyColor();
};
class Point
{
private:
    int x, y;

public:
    Point();
    Point(int, int);
    void displayPoint();
    ~Point();
};

class Circle : public MyColor
{
private:
    Point central;
    double radius;

public:
    Circle();
    double getArea();
    void displayCircle();
    bool operator>(Circle);
    void set();
};
MyColor::MyColor()
{
    this->colorID = "#ff000";
}
void MyColor::set(){
    cout << "nhap ma mau:";
    fflush(stdin);
    getline(cin, this->colorID);
}
void MyColor::displayColor()
{
    cout << "it is colorID: " << this->colorID << endl;
}
MyColor::~MyColor() {}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::displayPoint()
{
    cout << "No co toa do la: (" << this->x << ", " << this->y <<")"<< endl;
}
Point::~Point() {}

Circle::Circle()
{
    this->central = Point();
    this->radius = 0;
}
void Circle::set()
{
    MyColor::set();
    int x, y;
    cout << "Nhap toa do tam: " << endl
         << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    this->central = Point(x, y);
    cout << "Nhap ban kinh: ";
    cin >> this->radius;
}
double Circle::getArea()
{
    return pow(this->radius, 2) * PI;
}
bool Circle::operator>(Circle circle)
{
    return this->getArea() > circle.getArea() ? true : false;
}
void Circle::displayCircle()
{
    central.displayPoint();
    cout << "it has a radius of: " << this->radius << endl;
    cout << "it is colored: " << this->colorID << endl;
}
int main(int argc, char const *argv[])
{
    Circle circle[100];
    int n;
    cout << "nhap so luong duong tron: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin duong tron thu: " << i << endl;
        circle[i].set();
    }
    Circle maxArea = circle[0];
    for (int i = 1; i < n; i++)
    {
        if(circle[i] > maxArea){
            maxArea = circle[i];
        }
    }
    cout << "Duong tron co dien tich lon nhat: " << endl;
    maxArea.displayCircle();
    system("pause");
    return 0;
}

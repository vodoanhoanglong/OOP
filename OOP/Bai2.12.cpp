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
    friend istream &operator>>(istream &is, Point &point);
    double distanceTo(Point);
    void displayPoint();
    ~Point();
};
class Triangle : public MyColor
{
private:
    Point A, B, C;

public:
    Triangle();
    Triangle(Point, Point, Point);
    void set();
    double getPerimeter();
    void displayTriangle();
    bool operator>(Triangle);
    ~Triangle();
};
MyColor::MyColor()
{
    this->colorID = "#ff000";
}
void MyColor::set()
{
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
istream &operator>>(istream &is, Point &point)
{
    cout << "\nNhap Hoanh Do: ";
    is >> point.x;
    cout << "\nNhap so mu: ";
    is >> point.y;
    return is;
}
double Point::distanceTo(Point X)
{
    return sqrt(pow(this->x - X.x, 2) + pow(this->y - X.y, 2));
}
void Point::displayPoint()
{
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}
Point::~Point() {}
Triangle::Triangle()
{
    this->A = Point();
    this->B = Point();
    this->C = Point();
}
Triangle::Triangle(Point X, Point Y, Point Z)
{
    double a = X.distanceTo(Y);
    double b = Y.distanceTo(Z);
    double c = Z.distanceTo(X);
    if (a < b + c && b < a + c && c < a + b)
    {
        this->A = X;
        this->B = Y;
        this->C = Z;
    }
    else
    {
        cout << "Khong tao duoc tam giac tu 3 diem do!" << endl;
    }
}
void Triangle::set()
{

    cout << "Nhap toa do 3 diem:" << endl;
    cout << "Diem A: ";
    cin >> this->A;
    cout << "Diem B: ";
    cin >> this->B;
    cout << "Diem C: ";
    cin >> this->C;
}
double Triangle::getPerimeter()
{
    double a = this->A.distanceTo(this->B);
    double b = this->B.distanceTo(this->C);
    double c = this->C.distanceTo(this->A);
    return a + b + c;
}
bool Triangle::operator>(Triangle triangle)
{
    return this->getPerimeter() > triangle.getPerimeter() ? true : false;
}
void Triangle::displayTriangle()
{
    cout << "Toa Do cua cac dinh lan luot là: " << endl;
    cout << "Dinh A: ";
    this->A.displayPoint();
    cout << "Dinh B: ";
    this->B.displayPoint();
    cout << "Dinh C: ";
    this->C.displayPoint();
    cout << "Tam giac nay co mau: " << this->colorID << endl;
    cout << "Co Chu Vi = " << getPerimeter() << endl;
}
int main(int argc, char const *argv[])
{
    Triangle triangle[50];
    int n;
    cout << "nhap so luong duong tron: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin duong tron thu: " << i << endl;
        triangle[i].set();
    }
    Triangle maxPer = triangle[0];
    for (int i = 1; i < n; i++)
    {
        if (triangle[i] > maxPer)
        {
            maxPer = triangle[i];
        }
    }
    cout << "Tam giac co chu vi lon nhat: " << endl;
    maxPer.displayTriangle();
    system("pause");
    return 0;
}

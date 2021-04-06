#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Diem
{
    private:
        float x;
        float y;
    public:
        Diem();
        Diem(float x, float y);
        Diem(const float a);
        // ~Diem();
        void Nhap(float &a);
        void Xuat(Diem a);
        friend double KhoangCach(Diem d1, Diem d2);
        friend bool Check(Diem A, Diem B, Diem C);
        friend float CalculatorS(Diem A, Diem B, Diem C);
        friend double CalculatorP(Diem A, Diem B, Diem C);
        ~Diem()
        {
        }
};

Diem::Diem()
{
    x = 0;
    y = 0;
}
Diem::Diem(float x, float y)
{
    this->x = x;
    this->y = y;
}
Diem::Diem(const float a)
{
    x = a;
    y = a;
}
void Diem::Nhap(float &a)
{
    cout << "\nEnter 2 point: "; cin >> a.x >> a.y;
}
void Diem::Xuat(Diem a)
{
        cout << "(" << a.x << "," << a.y <<")";
}
double KhoangCach(Diem d1, Diem d2)
{
    
	double kc;
	kc=sqrt(pow((d1.x-d2.x),2)+pow((d1.y-d2.y),2));
	return kc;
}
bool Check(Diem A, Diem B, Diem C)
{
    double AB, BC, AC;
    AB = KhoangCach(A, B);
    BC = KhoangCach(B, C);
    AC = KhoangCach(A, C);
    if(AB == BC || AB == AC || AC==BC)
        return true;
    return false;
}
float CalculatorS(Diem A, Diem B, Diem C)
{
    float h = sqrt(KhoangCach(A,B)*KhoangCach(A,C)-pow(KhoangCach(B,C)/2,2));
    float S = (KhoangCach(B,C)/2)*h;
    return S;
}
double CalculatorP(Diem A, Diem B, Diem C)
{
    double P = KhoangCach(A,B) + KhoangCach(A,C) + KhoangCach(B,C);
    return P;
}
int main()
{  
    Diem  d;
    float a, b, c;
    cout << "\nPoint A:";
    d.Nhap(a);
    cout << "\nPoint B:";
    d.Nhap(b);
    cout << "\nPoint C:";
    d.Nhap(c);
    cout << "A"; 
    d.Xuat(a);
    cout << "\nB";
    d.Xuat(b);
    cout << "\nC";
    d.Xuat(c);
    cout << "\nLength 2 point AB: "<<setprecision(2) << KhoangCach(a, b)<<"cm";
    if(Check(a, b, c))
        cout << "\nIt's a isosceles triangle";
    else   cout << "\nIt not's a isosceles triangle";
    cout << "\nAcreage: "<<setprecision(2) << CalculatorS(a, b, c)<<"cm";
    cout << "\nPerimeter: "<<setprecision(2) << CalculatorP(a, b, c)<<"cm";
}
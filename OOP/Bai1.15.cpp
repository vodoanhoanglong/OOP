#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class vector{
    private:
        int n;
        float *v;
    public:
        vector(int size);
        vector(vector &vt);
        ~vector();
        void Nhap();
        void Xuat();
        int Check(vector &vt);
        friend vector operator +(vector &vt1,vector &vt2);
        void operator =(vector &vt);
};
vector::vector(int size)
{
    n = size;
    v = new float [n];
}

vector::vector(vector &vt)
{
    n = vt.n;
    v = new float [n];
    for (int i = 0; i < n; i++)
    v[i] = vt.v[i];
}
vector::~vector()
{
    delete v;
}
void vector::Nhap()
{
    for (int i = 0; i < n; i++)
    {
        cout<<"v["<<i<<"]: ";
        cin>>v[i];
    }
}

void vector::Xuat()
{
    for (int i = 0; i < n; i++)
    cout<<v[i]<<"       ";
}

int vector::Check(vector &vt)
{
    if (n == vt.n) 
        return 1;
    return 0;
}
vector operator +(vector &vt1,vector &vt2)
{
    vector c = vt1;
    for (int i = 0;i < vt1.n; i++)
    c.v[i] = vt1.v[i] + vt2.v[i];
    return c;
}

void vector:: operator =(vector &vt)
{
    n = vt.n;
    v = new float [n];
    for (int i = 0; i < n; i++)
    v[i] = vt.v[i];
}

int main()
{
    int n;
    vector a(n), b(n);
    cout<<"Nhap so phan tu cua vector a: ";cin>>n;
    cout<<"Nhap vector a: \n"; a.Nhap();
    cout<<"\nNhap so phan tu cua vector b: ";cin>>n;
    cout<<"Nhap vector b: \n";b.Nhap();
    cout<<"vector a: ";a.Xuat();
    cout<<"\nvector b: ";b.Xuat();
    if(a.Check(b)==1) 
    {
        cout<<"\nvector tong la: ";
        (a+b).Xuat();
    }
    else 
        cout<<"\nK cong duoc 2 vector nay: ";

    system("pause");
    return 0;
}
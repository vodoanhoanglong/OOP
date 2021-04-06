//Bài 1.5, 1.6, 1.7
#include <iostream>
using namespace std;

class PhanSo
{
    private:
        float tu, mau;
    public:
        PhanSo();
        PhanSo(float tu, float mau);
        PhanSo(const float a);
        ~PhanSo();
        void Input();
        void Output();
        void compact();
        PhanSo operator+(PhanSo ps);
        PhanSo operator-(PhanSo ps);
        PhanSo operator*(PhanSo ps);
        PhanSo operator/(PhanSo ps);
        friend bool operator>(PhanSo ps1, PhanSo ps2);
        friend bool operator>=(PhanSo ps1, PhanSo ps2);
        friend bool operator<(PhanSo ps1, PhanSo ps2);
        float sum();
};

PhanSo::PhanSo()
{
    this->tu=0;
    this->mau=1;
}
PhanSo::PhanSo(float tu, float mau)
{
    this->tu = tu;
    this->mau = mau;
}
PhanSo::PhanSo(const float a)
{
    this->tu = this->mau = a;
}
PhanSo::~PhanSo()
{

}
void PhanSo::Input()
{
    cout << "\nNhap tu: " <<endl; cin >> tu;
    do{
        cout << "\nNhap mau: "<<endl; cin >> mau;
        if(mau == 0)
            cout<<"Mau phai khac 0!!!"<<endl;
    }while(mau == 0);
}
void PhanSo::Output()
{
    compact();
    if(tu == 0 || mau == 1)
        cout<<tu<<endl;
    else cout<<tu<<"/"<<mau<<endl;
}
int greatestCommonDivisor(int number1, int number2)
{
    if (number2 == 0) return number1;
    return greatestCommonDivisor(number2, number1 % number2);
}
void PhanSo::compact()
{
    int greatest_common_divisor = greatestCommonDivisor(tu, mau);
    tu = tu / greatest_common_divisor;
    mau = mau / greatest_common_divisor; 
}
PhanSo PhanSo::operator+(PhanSo ps)
{
    return PhanSo((this->tu * ps.mau) + (this->mau * ps.tu), this->mau * ps.mau);
}

PhanSo PhanSo::operator-(PhanSo ps)
{
    return PhanSo((this->tu * ps.mau) - (this->mau * ps.tu), this->mau * ps.mau);
}

PhanSo PhanSo::operator*(PhanSo ps)
{
    return PhanSo(this->tu * ps.tu, this->mau * ps.mau);
}

PhanSo PhanSo::operator/(PhanSo ps)
{
    return PhanSo(this->tu * ps.mau, this->mau * ps.tu);
}

bool operator>(PhanSo ps1, PhanSo ps2)
{
    float gt1 = ps1.tu / ps1.mau;
    float gt2 = ps2.tu / ps2.mau;
    return (gt1>gt2)?true:false;
}
bool operator>=(PhanSo ps1, PhanSo ps2)
{
    float gt1 = ps1.tu / ps1.mau;
    float gt2 = ps2.tu / ps2.mau;
    return (gt1>=gt2)?true:false;
}

bool operator<(PhanSo ps1, PhanSo ps2)
{
    float gt1 = ps1.tu / ps1.mau;
    float gt2 = ps2.tu / ps2.mau;
    return (gt1<gt2)?true:false;
}
float PhanSo::sum()
{
    return this->tu / this->mau;
}

int main()
{
    int n;
    PhanSo *a, t(0,1), b(2,5), c(4,5), d;
    d = b / c;
    cout<<"Phep chia" << endl;
    d.Output();
    cout<<"So sanh > : "<<endl;
    if(b>c) cout<<"PS1 > PS2"<<endl;
    else cout<<"PS1 < PS2"<<endl;
    cout<<"So sanh >= : "<<endl;
    if(b>=c) cout<<"PS1 >= PS2"<<endl;
    else cout<<"PS1 <= PS2"<<endl;
    cout<<"Nhap so luong phan so: " << endl; cin>>n;
    a = new PhanSo[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap phan so thu " << i+1<<": ";
        a[i].Input();
        t = t + a[i];
    }
    cout<<"Tong cac phan so la: "<<endl;
    t.Output();
    cout<<"Sap xep phan so tang dan: "<<endl;
    for(int i=0; i<n-1;i++)
        for(int j=1; j<n; j++)
            if(a[i] > a[j])
            {
                PhanSo temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    for(int i=0; i<n; i++)
        a[i].Output();
    PhanSo max = a[0];
    for(int i=1; i<n; i++)
        if(a[i] > max)
            max = a[i];
    cout<<"Phan so lon nhat co gia tri la: " <<endl;
    max.Output();
    PhanSo min = a[0];
    for(int i=1; i<n; i++)
        if(a[i] < min)
            min = a[i];
    cout<<"Phan so nho nhat co gia tri la: " <<endl;
    min.Output();
    system("pause");
}

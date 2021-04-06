#include <iostream>
using namespace std;

class PhanSo
{
    private:
       int tu;
       int mau;
    public:
       PhanSo();
       PhanSo(int a, int b);
       ~PhanSo();
       void Set(int a, int b);
       int getTu();
       int getMau();
       void Nhap();
       void Xuat();
       void NghichDao();
       void RutGon();
       PhanSo Cong(PhanSo b);
       PhanSo Tru(PhanSo b);
       PhanSo Nhan(PhanSo b);
       PhanSo Chia(PhanSo b);
       bool SoSanh(PhanSo b);
};

PhanSo::PhanSo()
{
    tu = 0;
    mau = 1;
}
PhanSo::PhanSo(int a, int b)
{
    tu = a;
    mau = b;
}
PhanSo::~PhanSo() 
{
}
void PhanSo::Set(int a, int b)
{
    a = tu;
    b = mau;
}
int PhanSo::getTu()
{
    return this -> tu;
}
int PhanSo::getMau()
{
    return this -> mau;
}
void PhanSo::Nhap()
{
    cout << "\nNhap tu: "; cin >> tu;
    do{
        cout << "\nNhap mau: "; cin >> mau;
    }while(mau == 0);
}
void PhanSo::Xuat()
{
    if(tu==0)
        cout << tu;
    else 
        cout << endl << tu << "/" << mau;
}
void PhanSo::NghichDao()
{
    int temp;
    temp = tu;
    tu = mau;
    mau = temp;
}
int uocChungLonNhat(int number1, int number2)
{
     if (number2 == 0) return number1;
    return uocChungLonNhat(number2, number1 % number2);
}
void PhanSo::RutGon()
{
    int uocchunglonnhat = uocChungLonNhat(tu, mau);
    tu = tu / uocchunglonnhat;
    mau = mau / uocchunglonnhat;
}
PhanSo PhanSo::Cong(PhanSo b)
{
    return PhanSo((this->tu*b.mau)+(this->mau*b.tu), this->mau*b.mau);
}
PhanSo PhanSo::Tru(PhanSo b)
{
    return PhanSo((this->tu*b.mau)-(this->mau*b.tu), this->mau*b.mau);
}
PhanSo PhanSo::Nhan(PhanSo b)
{
    return PhanSo(this->tu*b.tu, this->mau*b.mau);
}
PhanSo PhanSo::Chia(PhanSo b)
{
    return PhanSo(this->tu*b.mau, this->mau*b.tu);
}
bool PhanSo::SoSanh(PhanSo b)
{
    if((tu/mau)>(b.tu/b.mau))
        return  true;
    else
        return false;
}
int main()
{
    PhanSo a(2, 6), b(4, 5), c;
    c = a.Cong(b);
    c.RutGon();
    c.Xuat();
    if(c.SoSanh(b) == true)
         cout << "\nc > b";
    else cout << "\nc < b";
    c.NghichDao();
    c.Xuat();
}

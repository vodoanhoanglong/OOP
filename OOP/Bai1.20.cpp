#include <iostream>
using namespace std;

class Complex
{
private:
    float PhanThuc, PhanAo;
public:
    Complex();
    Complex(float PhanThuc, float PhanAo);
    Complex(const float c);
    void Nhap();
    void Xuat();
    Complex operator +(Complex sp);
    Complex operator -(Complex sp);

};

Complex::Complex()
{
    this->PhanThuc = 1;
    this->PhanAo = 1;
}
Complex::Complex(float PhanThuc, float PhanAo)
{
    this->PhanThuc = PhanThuc;
    this->PhanAo = PhanAo;
}
Complex::Complex(const float c)
{
    this->PhanThuc = this->PhanAo = c;
}

void Complex::Nhap()
{
    cout << endl << "Nhap phan thuc: "; cin >> PhanThuc;
    cout << endl << "Nhap phan ao: "; cin >> PhanAo;
}

void Complex::Xuat()
{
    if (PhanThuc == 0)
    {
        if (PhanAo > 0)
            cout <<"("<< PhanThuc << "+" << PhanAo << "i)";
        else if (PhanAo == 0)
            cout << PhanThuc;
        else
            cout << "("<< PhanThuc << " " << PhanAo << "i)";
    }else
    {
        if(PhanAo > 0)
            cout << "("<< PhanThuc << " + " << PhanAo <<"i)";
        else if(PhanAo == 0)
            cout << PhanThuc;
        else 
            cout <<"("<< PhanThuc << " " << PhanAo << "i)";
    }
}

Complex Complex::operator +(Complex sp)
{
    return Complex(this->PhanThuc + sp.PhanThuc, this->PhanAo + sp.PhanAo);
}

Complex Complex::operator -(Complex sp)
{
    return Complex(this->PhanThuc - sp.PhanThuc, this->PhanAo - sp.PhanAo);
}

int main()
{
    Complex sp1, sp2, z, *c;
    
    sp1.Nhap();
    sp2.Nhap();
    z = sp1 + sp2;
    sp1.Xuat();cout<<" + ";sp2.Xuat();cout<<" = " ;z.Xuat();cout<<endl;

    z = sp1 - sp2;
    sp1.Xuat();cout<<" - ";sp2.Xuat();cout<<" = " ;z.Xuat();cout<<endl;

    system("pause");
    return 0;
}
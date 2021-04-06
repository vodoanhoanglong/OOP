//Bài 1.1, 1.2
#include <iostream>
using namespace std;

class Complex
{
private:
    float a, b;

public:
    Complex();
    Complex(float a, float b);
    Complex(const float c);
    void Nhap();
    void Xuat();
    friend Complex operator+(Complex sp1, Complex sp2);
    friend Complex operator-(Complex sp1, Complex sp2);
    Complex operator=(Complex sp);
};

Complex::Complex()
{
    this->a = 1;
    this->b = 1;
}
Complex::Complex(float a, float b)
{
    this->a = a;
    this->b = b;
}
Complex::Complex(const float c)
{
    this->a = this->b = c;
}

void Complex::Nhap()
{
    cout << endl << "Nhap phan thuc: "; cin >> a;
    cout << endl << "Nhap phan ao: "; cin >> b;
}

void Complex::Xuat()
{
    if (a == 0)
    {
        if (b > 0)
            cout << endl << a << "+" << b << "i";
        else if (b == 0)
            cout << endl << a << "";
        else
            cout << endl << a << "" << b << "i";
    }else
    {
        if(b>0)
            cout << endl << a << " + " << b << "i";
        else if(b==0)
            cout << endl << a;
        else 
            cout << endl << a << b << "i";
    }
}

Complex operator+(Complex sp1, Complex sp2)
{
    return Complex(sp1.a + sp2.a, sp1.b + sp2.b);
}

Complex operator-(Complex sp1, Complex sp2)
{
    return Complex(sp1.a - sp2.a, sp1.b - sp2.b);
}

Complex Complex::operator=(Complex sp)
{ 
    return Complex(this->a = sp.a, this->b = sp.b);
} 
int main()
{
    int n;
    Complex x(10, 5), y(5, 10), z, *c, t(0);
    z = x + y;
    z.Xuat();
    z = x - y;
    z.Xuat();
    cout<<endl<<"Nhap vao n so phuc: "; cin >> n;
    c = new Complex[n];
    for(int i=0; i<n; i++)
    {
        cout<<endl<<"Nhap so phuc " << i+1<<": ";
        c[i].Nhap();
        t = t + c[i];
    }
    cout<<endl<<"Tong cac so phuc da nhap: ";
    t.Xuat();
    cout<<endl;
    system("pause");
}

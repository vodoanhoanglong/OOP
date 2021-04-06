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
    bool operator ==(Complex sp); 

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
bool Complex::operator ==(Complex sp)
{
    if((this->PhanThuc == sp.PhanThuc) && (this->PhanAo == sp.PhanAo)) 
        return true;
    return false;
}

int main()
{
   Complex sp[5], x;
    // Nhập mảng 
    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap vao So Phuc thu "<<i + 1<<": "<<endl;
        sp[i].Nhap();
    }
    
    // Xuất mảng Phân Số vừa nhập
    cout<<"___________________________________"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<"\nSo Phuc thu"<<i + 1<<": ";
        sp[i].Xuat(); 
    }

    // Tìm kiếm x
    cout<<"\nNhap So Phuc can tim: "; x.Nhap();
    int dem = 0; //Biến đếm để biết số lần x xuất hiện trong mảng
    for(int i = 0; i < 5; i++) 
    {
        if (sp[i] == x) 
        {
            dem++;
            cout<<"So Phuc "; x.Xuat(); cout<<" co trong mang"<<endl; 
            
        } 
        cout<<"Tai vi tri thu "<<i<<endl;
    }
    if(dem == 0)
        { 
            cout<<"Khong co So Phuc " ; x.Xuat() ; cout<<" trong mang "<<endl; 
        }

    system("pause");
    return 0;
}
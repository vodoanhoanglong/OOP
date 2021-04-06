#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc
{
    private:
        int thuc;
        int ao;
    public:
        SoPhuc()
        {
            thuc = 1;
            ao = 1;
        }
        SoPhuc(int a, int b)
        {
            thuc = a;
            ao = b;
        }
        ~SoPhuc()
        {

        }
        int getThuc()
        {
            return this->thuc;
        }
        int getAo()
        {
            return this->ao;
        }
        void Nhap();
        void Xuat();
        float Module();
        SoPhuc Cong(SoPhuc b);
        SoPhuc Tru(SoPhuc b);
        SoPhuc Nhan(SoPhuc b);
        SoPhuc Chia(SoPhuc b);
        bool SoSanh(SoPhuc b);
};
void SoPhuc::Nhap()
{
    cout <<"\nNhap phan thuc: ";
    cin >> thuc;
    cout << "\nNhap phan ao: ";
    cin >> ao;
}
void SoPhuc::Xuat()
{
if(thuc > 0 || thuc < 0)
{
    if(ao > 0)
        cout << endl << thuc << "+" << ao << "i";
    else if(ao == 0)
        cout << endl << thuc << "";
    else
        cout << endl << thuc << "" << ao << "i";
}else if(thuc==0){
    if(ao > 0)
        cout << endl << thuc << "" << ao << "i";
    else if(ao == 0)
        cout << endl << thuc << "";
    else
        cout << endl << thuc << "" << ao << "i";
}   
}
float SoPhuc::Module()
{ 
    return sqrt(pow(thuc,2) + pow(ao, 2));
}
SoPhuc SoPhuc::Cong(SoPhuc b)
{
    return SoPhuc(this->thuc+b.thuc, this->ao+b.ao);
}
SoPhuc SoPhuc::Tru(SoPhuc b)
{
    return SoPhuc(this->thuc-b.thuc, this->ao-b.ao);
}
SoPhuc SoPhuc::Nhan(SoPhuc b)
{
    return SoPhuc(this->thuc*b.thuc, this->ao*b.ao);
}
SoPhuc SoPhuc::Chia(SoPhuc b)
{
    return SoPhuc(this->thuc/b.thuc, this->ao/b.ao);
}
bool SoPhuc::SoSanh(SoPhuc b)
{
    if(Module()>b.Module())
        return true;
    else return false;
}
int main()
{
    SoPhuc a(2,-3), b(4,3), c;
    a.Xuat();
    cout << "\n" <<a.Module();
    c = a.Chia(b);
    c.Xuat();
    if(a.SoSanh(b)==true)
       cout << "\na>b";
    else cout << "\na<b";
}

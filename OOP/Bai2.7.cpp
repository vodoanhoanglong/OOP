#include <iostream>
using namespace std;
#include <string>
class SV
{
    private:
        string lop, hoTen;
    public:
        SV();
        ~SV();
        void input();
        void display();
};
SV::SV()
{
    this->lop = "";
    this->hoTen = "";
}
SV::~SV()
{

}
void SV::input()
{
    cout<<"Nhap lop hoc cua sv: "<<endl;
    getline(cin, lop);
    cout<<"Nhap ho ten sv: "<<endl;
    getline(cin, hoTen);
}
void SV::display()
{
    cout<<"Lop cua sv la: "<<lop<<endl;
    cout<<"Ho ten sv la: "<<hoTen<<endl;
}
class SVTC : public SV
{
    private:
       long int hocPhi;
    public:
        SVTC();
        ~SVTC();
        void input();
        void display();
};
SVTC::SVTC()
{
    this->hocPhi = 0;
}
SVTC::~SVTC()
{

}
void SVTC::input()
{
    SV::input();
    cout<<"Nhap hoc phi cua sv: "<<endl;
    cin>>hocPhi;
}
void SVTC::display()
{
    SV::display();
    cout<<"Hoc phi cua sv la: "<<hocPhi<<endl;
}
class SVCN : public SVTC
{
    private:
        float DTB;
        string hocBong;
    public:
        SVCN();
        ~SVCN();
        void input();
        void display();
        bool operator>(SVCN sv);
};
SVCN::SVCN()
{
    this->DTB = 0;
    this->hocBong = "";
}
SVCN::~SVCN()
{

}
void SVCN::input()
{
    SVTC::input();
    cout<<"Nhap diem trung binh cua sv: "<<endl;
    cin>>DTB;
    cout<<"Nhap loai hoc bong cua sv: "<<endl;
    cin.ignore();
    getline(cin, hocBong);
}
void SVCN::display()
{
    SVTC::display();
    cout<<"Diem trung binh cua sv la: "<<DTB<<endl;
    cout<<"Loai hoc bong cua sv la: "<<hocBong<<endl;
}
bool SVCN::operator>(SVCN sv)
{
    if(this->DTB > sv.DTB)
       return true;
    return false;
}
int main()
{
    SVCN *a = new SVCN[3];
    for(int i=0; i<3; i++)
    {
        cout<<"-Nhap vao sv thu "<<i+1<<": "<<endl;
        a[i].input();
    }
    for(int i=0; i<3-1; i++)
       for(int j=1; j<3; j++)
           if(a[j] > a[i])
           {
               SVCN temp = a[i];
               a[i] = a[j];
               a[j] = temp;
           }
    for(int i=0; i<3; i++)
    {
        cout<<"-Thong tin sv thu "<<i+1<<": "<<endl;
        a[i].display();
    }
    system("pause");
}
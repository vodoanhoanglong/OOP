#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    string Lop;
    string HoTen;

public:
    SinhVien();
    ~SinhVien();
    void Nhap();
    void Xuat();
};
SinhVien::SinhVien()
{
    Lop = "";
    HoTen = "";
}
SinhVien::~SinhVien()
{
}
void SinhVien::Nhap()
{
    cout << "Nhap lop cua sinh vien: " << endl;
    getline(cin, Lop);
    cout << "Nhap ho va ten sinh vien: " << endl;
    getline(cin, HoTen);
}
void SinhVien::Xuat()
{
    cout << "Lop: " << Lop << endl;
    cout << "Ho va ten: " << HoTen << endl;
}
class SVTC : public SinhVien
{
private:
    long HocPhi;

public:
    SVTC();
    void Nhap();
    void Xuat();
};
SVTC::SVTC()
{
    HocPhi = 0;
}
void SVTC::Nhap()
{
    SinhVien::Nhap();
    cout << "Nhap hoc phi cua sinh vien: " << endl;
    cin >> HocPhi;
}
void SVTC::Xuat()
{
    SinhVien::Xuat();
    cout << "Hoc phi la: " << HocPhi << endl;
}
class SVCN : public SVTC
{
private:
    float DTB;
    string HocBong;

public:
    SVCN();
    void Nhap();
    void Xuat();
    bool operator>(SVCN cn);
    friend void SoSanh(SVCN *Sort, int n);
};
SVCN::SVCN()
{
    DTB = 0;
    HocBong = "";
}
void SVCN::Nhap()
{
    SVTC::Nhap();
    cout << "Nhap diem trung binh cua sinh vien: " << endl;
    cin >> DTB;
    cout << "Nhap loai hoc bong cua sinh vien: " << endl;
    cin.ignore();
    getline(cin, HocBong);
}
void SVCN::Xuat()
{
    SVTC::Xuat();
    cout << "Diem trung binh la: " << DTB << endl;
    cout << "Loai hoc bong: " << HocBong << endl;
}
bool SVCN::operator>(SVCN cn)
{
    if (this->DTB > cn.DTB)
        return true;
    return false;
}
void SoSanh(SVCN *Sort, int n)
{
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((Sort + i)->DTB < (Sort + j)->DTB)
            {
                SVCN *temp;
                temp = new SVCN[n];
                *(temp+i) = *(Sort + i);
                *(Sort + i) = *(Sort + j);
                *(Sort + j) = *(temp+i);
            }
        }
    }
    for(int i=0; i<n; i++)
        (Sort+i)->Xuat();
}
int main()
{
    SVCN svcn1, svcn2, svcn3;
    cout << "\t\t\t\t\tThong Tin SV 1" << endl;
    svcn1.Nhap();
    svcn1.Xuat();
    cout << "\t\t\t\t\tThong Tin SV 2" << endl;
    svcn2.Nhap();
    svcn2.Xuat();
    cout << "\t\t\t\tSo sanh 2 sinh vien theo DTB" << endl;
    if (svcn1 > svcn2)
        cout << "sv1 > sv2";
    else
        cout << "sv1 < sv2";
    cout << "\t\t\t\t\tThong Tin SV 3" << endl;
    svcn3.Nhap();
    svcn3.Xuat();
    
    SVCN *Sort;
    int n = 3;
    Sort = new SVCN[n];
    *(Sort+0) = svcn1;
    *(Sort+1) = svcn2;
    *(Sort+2) = svcn3;
    cout<<"\t\t\t\tXuat danh sach theo diem TB giam dan"<<endl;
    SoSanh(Sort, n);
    system("pause");
}

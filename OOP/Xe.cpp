#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Xe
{
private:
    string BienSo;
    float TrongLuong;

public:
    Xe();
    ~Xe();
    float Get_TrongLuong()
    {
        return TrongLuong;
    }
    void Nhap();
    void Xuat();
};
Xe::Xe()
{
    BienSo = "";
    TrongLuong = 0;
}
Xe::~Xe()
{
}
void Xe::Nhap()
{
    cin.ignore();
    cout << "Nhap vao bien so: ";
    getline(cin, BienSo);
    cout << "Nhap vao trong luong(kg): ";
    cin >> TrongLuong;
}
void Xe::Xuat()
{
    cout << "Bien So: " << BienSo << endl;
    cout << "Trong Luong: " << TrongLuong << " kg" << endl;
}

class XeCon : public Xe
{
private:
    int SoChoNgoi;

public:
    XeCon();
    ~XeCon();
    int Get_SoChoNgoi()
    {
        return SoChoNgoi;
    }
    void Nhap();
    void Xuat();
    void KiemTra(XeCon *xc, int n);
};
void Nhap_DS_XeCon(XeCon *xc, int n);
XeCon::XeCon()
{
    SoChoNgoi = 0;
}
XeCon::~XeCon()
{
}
void XeCon::Nhap()
{
    Xe::Nhap();
    cout << "Nhap so cho ngoi: ";
    cin >> SoChoNgoi;
}
void XeCon::Xuat()
{
    Xe::Xuat();
    cout << "So Cho Ngoi: " << SoChoNgoi << endl;
}
void Nhap_DS_XeCon(XeCon *xc, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap Xe Con thu " << i + 1 << endl;
        (xc+i)->Nhap();
    }
}

void XeCon::KiemTra(XeCon *xc, int n)
{
    for(int i = 0; i < n; i++)
    {
        if((xc+i)->Get_TrongLuong() < 1000 && (xc+i)->Get_SoChoNgoi() < 5)
        {
            cout<<"\nXe con thu "<<i+1<<endl;
            (xc+i)->Xuat();
        }
    }
}

class XeTai : public Xe
{
private:
    float TaiTrong;

public:
    XeTai();
    ~XeTai();
    float Get_TaiTrong()
    {
        return TaiTrong;
    }
    void Nhap();
    void Xuat();
    void KiemTra(XeTai *xt, int m);
};
void Nhap_DS_XeTai(XeTai *xt, int m);
XeTai::XeTai()
{
    TaiTrong = 0;
}
XeTai::~XeTai()
{
}
void XeTai::Nhap()
{
    Xe::Nhap();
    cout << "Nhap Tai Trong: ";
    cin >> TaiTrong;
}
void XeTai::Xuat()
{
    Xe::Xuat();
    cout << "Tai Trong: " << TaiTrong << endl;
}
void Nhap_DS_XeTai(XeTai *xt, int m)
{

    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap Xe Tai thu " << i + 1 << endl;
        (xt+i)->Nhap();
    }
}
void XeTai::KiemTra(XeTai *xt, int m)
{
    XeTai temp[100];
    int length = 0;
    for(int i=0; i<m; i++)
    {
        if(xt[i].Get_TrongLuong() >= 3000)
        {
            temp[length] = xt[i];
            length++;
        }
    }
    if(length == 0)
    {
        cout<<"Khong co"<<endl;
        return;
    }
    XeTai min = temp[0];
    for(int i=0; i<length; i++)
    {
        if(min.Get_TaiTrong() > temp[i].Get_TaiTrong())
            min = temp[i];
    }
    min.Xuat();
    // int dem=0, j = 0;
    // XeTai temp;
    // float min;
    // for(int i=0; i<m; i++)
    // {
    //     if((xt+i)->Get_TrongLuong() > 5000)
    //     {
    //         min = (xt + j)->Get_TaiTrong();
    //         break;
    //     }
    //     else j++;
    // }   
    // for (int i = 0; i < m; i++)
    // {
    //     if ((xt+i)->Get_TrongLuong() > 5000 && (xt+i)->Get_TaiTrong() < min)
    //     {
    //             min = (xt + i)->Get_TaiTrong();
    //             temp = xt[i];
    //             dem++;
    //     }
    // }
    // if(dem==0)
    //     if(j==m)
    //     {
    //         cout<<"Ko co"<<endl;
    //         return;
    //     }
    //     else
    //         temp=xt[j];    
    // temp.Xuat();
}
int main()
{
    int n, m, luachon;
    XeCon *xc;
    XeTai *xt;

    // while (true)
    // {
    //     system("cls");
    //     cout << "\n 1. Nhap thong tin";
    //     cout << "\n 2. Xe Con co trong luong < 1000kg && SCN < 5";
    //     cout << "\n 3. Xe Tai co Tai Trong > 5000kg va co tai trong min";
    //     cout << "\n 0. Thoat";

    //     cout << "\nNhap lua chon cua ban: ";
    //     cin >> luachon;
    //     switch (luachon)
    //     {
    //     case 1:
    //     {
            cout << "\nNhap vao so luong Xe Con: ";
            cin >> n;
            xc = new XeCon[n];
            Nhap_DS_XeCon(xc, n);
            cout << "\nNhap vao so luong Xe Tai: ";
            cin >> m;
            xt = new XeTai[m];
            Nhap_DS_XeTai(xt, m);
        //     break;
        // }
        // case 2:
        // {
        //     xc->KiemTra(xc, n);
        //     system("pause");
        //     break;
        // }
        // case 3:
        // {
            xt->KiemTra(xt, m);
            system("pause");
    //         break;
    //     }
    //     case 0: 
    //     {
    //         exit(0);
    //     }
    //     default:
    //     {
    //         cout << "\nLua chon khong hop le. Xin vui long kiem tra lai!!!" << endl;
    //         system("pause");
    //         break;
    //     }
    //     }
    // }
    return 0;
}

 
 
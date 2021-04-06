#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    int MSSV, NamSinh;
    string HoTen;
    float DTB;
    SinhVien *temp;
public:
    SinhVien();
    SinhVien(int MSSV, int NamSinh, string HoTen, float DTB);
    ~SinhVien();
    friend istream &operator>>(istream &in, SinhVien &sv);
    friend ostream &operator<<(ostream &os, SinhVien &sv);
    bool operator>(SinhVien sv);
    bool operator<(SinhVien sv);
    bool operator==(SinhVien sv);
    friend void Sapxep(int n, SinhVien *a);
    friend void Nhap(int n, SinhVien *sv);
    friend void Xuat(int n, SinhVien *sv);
    float getDTB();
    friend void ThongKe(int n, SinhVien *sv);
};
SinhVien::SinhVien()
{
    MSSV = 6051071067;
    HoTen = "Vo Doan Hoang Long";
    NamSinh = 2001;
    DTB = 10.0;
}
SinhVien::SinhVien(int MSSV, int NamSinh, string HoTen, float DTB)
{
    this->MSSV = MSSV;
    this->NamSinh = NamSinh;
    this->HoTen = HoTen;
    this->DTB = DTB;
}
SinhVien::~SinhVien()
{
}
istream &operator>>(istream &in, SinhVien &sv)
{
    cout << "\nNhap ma so sinh vien: ";
    in >> sv.MSSV;
    cout << "\nNhap nam sinh: ";
    in >> sv.NamSinh;
    cin.ignore();
    cout << "\nNhap HoTen:";
    getline(in, sv.HoTen);
    cout << "\nNhap DiemTrungBinh:";
    in >> sv.DTB;
    return in;
}
ostream &operator<<(ostream &os, SinhVien &sv)
{
    cout << "\nMSSV la: " << sv.MSSV;
    cout << "\nNam sinh:" << sv.NamSinh;
    cout << "\nHo Ten la:" << sv.HoTen;
    cout << "\nDTB la:" << sv.DTB;
    return os;
}
float SinhVien::getDTB()
{
    return this->DTB;
}
void Nhap(int n, SinhVien *a)
{
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
}
void Xuat(int n, SinhVien *a)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a + i)->NamSinh > (a + j)->NamSinh)
            {
                SinhVien *temp;
                temp = new SinhVien[n];
                *(temp+i) = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = *(temp+i);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << *(a + i);
}
bool SinhVien::operator>(SinhVien sv)
{
    if (this->DTB > sv.DTB)
        return true;
    return false;
}
bool SinhVien::operator<(SinhVien sv)
{
    if (this->DTB < sv.DTB)
        return true;
    return false;
}
bool SinhVien::operator==(SinhVien sv)
{
    if (this->DTB == sv.DTB)
        return true;
    return false;
}
void Sapxep(int n, SinhVien *a)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a + i)->DTB < (a + j)->DTB)
            {
                int temp = (a + i)->DTB;
                (a + i)->DTB = (a + j)->DTB;
                (a + j)->DTB = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << "\t" << (a + i)->DTB;
}
void ThongKe(int n, SinhVien *a)
{
    for(int i=0;i<n;i++){
       // vi getDTB() no tra ve gia tri nen no k can con tro phia trc
       float t =  (a+i)->getDTB();
       if(t < 1)
       cout<<"\nSinh vien bi canh cao la: "<<*(a+i);
    }
}
void Menu()
{
	int n, luachon;
    while(true)
    {
    	system("cls");
    	cout<<"\n1. Nhap danh sach Sinh vien";
    	cout<<"\n2. Xuat danh sach Sinh vien";
    	cout<<"\n3. Sap xep danh sach Sinh vien";
    	cout<<"\n4. Thong ke So luong SV bi canh cao";
    	cout<<"\n6. Thoat";
    	
    	cout<<"\nNhap lua chon cua ban";
    	cin>>luachon;
    	switch(luachon){
			case 1:
				cout << "\nNhap so luong sinh vien: ";
                cin >> n;
                SinhVien *a;
                a = new SinhVien[n];
                Nhap(n, a);
				break;
			case 2:
				Xuat(n, a);
				system("pause");
				break;
			case 3:
				Sapxep(n, a);
				Xuat(n, a);
				system("pause");
				break;
			case 4:
				ThongKe(n, a);
                cout<<endl;
                system("pause");
				break;
					
			case 5:
				exit(0);
			default:
				{
					cout<<"\nLua chon khong dung "<<endl;
					system("pause");
					break;
				}
		}
			
    }
}
int main()
{
    // SinhVien sv1, sv2;
    // cin>>sv1; cin>>sv2;
    // cout<<sv1;
    // cout<<sv2;
    // if(sv1>sv2) cout<<"\nSV1 > SV2";
    // else if(sv1<sv2) cout<<"\nSV1<SV2";
    // else cout<<"\nSV1=SV2";
    // system("pause");
    Menu();
    system("pause");
	return 0;
}	


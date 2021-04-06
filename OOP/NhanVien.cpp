#include<iostream>
using namespace std;
#include<string>

class NhanVien{
    private:
        int MSSV;
        string HoTen;
        int NamSinh;
        string PhongBan;
        float Luong;
    public:
        NhanVien();
        NhanVien(string MSSV, string HoTen);
        NhanVien(int MSSV, string HoTen, int NamSinh, string PhongBan, float Luong);
        ~NhanVien();
        float Get_Luong(){
            return this->Luong;
        }
        float Get_NamSinh(){
            return this->NamSinh;
        }
        friend istream &operator >> (istream &is, NhanVien &nv);
        friend ostream &operator << (ostream &os, NhanVien &nv);
        bool operator > (NhanVien nv);
        bool operator < (NhanVien nv);
        bool operator == (NhanVien nv);  
        friend void Nhap_DS_NhanVien(NhanVien *nv, int n);
        friend void Xuat_DS_NhanVien(NhanVien *nv, int n);
        friend void swap(NhanVien *a, NhanVien *b);
        friend void SapXep_Luong(NhanVien *nv, int n);
        friend void SapXep_NamSinh(NhanVien *nv, int n);
        friend void SelectionSort(NhanVien *nv, int n);
        friend void ThongKe_Luong(NhanVien *nv, int n);  


};
NhanVien::NhanVien()
{
    MSSV = 0;
    HoTen = "";
    NamSinh = 0;
    PhongBan = "";
    Luong = 0;   
}

NhanVien::NhanVien(string mssv, string hoten)
{
    MSSV = 0;
    HoTen = "";
    
}
NhanVien::NhanVien(int MSSV, string HoTen, int NamSinh, string PhongBan, float Luong)
{
    this->MSSV = MSSV;
    this->HoTen = HoTen;
    this->NamSinh = NamSinh;
    this->PhongBan = PhongBan;
    this->Luong = Luong;
}
NhanVien::~NhanVien()
{

}
istream &operator >> (istream &is, NhanVien &nv)
{
    cout<<"\nNhap ma so sinh vien: ";
    is>>nv.MSSV;
    cin.ignore();
    cout<<"\nNhap ho ten sinh vien: ";
    getline(is, nv.HoTen);
    cout<<"\nNhap nam sinh: ";
    is>>nv.NamSinh;
    cin.ignore();
    cout<<"\nNhap vao phong ban: ";
    getline(is, nv.PhongBan);
    cout<<"\nNhap vao tien Luong: ";
    is>>nv.Luong;
    return is;
}
ostream &operator <<(ostream &os, NhanVien &nv)
{
    os<<"MSSV: "<<nv.MSSV<<endl;
    os<<"Ho Ten Nhan Vien: "<<nv.HoTen<<endl;
    os<<"Nam Sinh: "<<nv.NamSinh<<endl;
    os<<"Phong Ban: "<<nv.PhongBan<<endl;
    os<<"Tien Luong: "<<nv.Luong<<endl;
    return os;
}
bool NhanVien::operator > (NhanVien nv)
{
    if(this->Luong > nv.Luong)
        return true;
    return false;
}
bool NhanVien::operator < (NhanVien nv)
{
    if(this->Luong < nv.Luong)
        return true;
    return false;
}
bool NhanVien::operator == (NhanVien nv)
{
    if(this->Luong == nv.Luong)
        return true;
    return false;
}      
void Nhap_DS_NhanVien(NhanVien *nv, int n)
{
    for(int i = 0; i < n; i++){
        cout<<"\nNhap thong tin sinh vien thu "<<i + 1;
        cin>> *(nv+i);
    }
}
void Xuat_DS_NhanVien(NhanVien *nv, int n){
    for(int i = 0; i < n; i++){
        cout<<"****************************"<<endl;
        cout<<"STT "<<i + 1<<endl;
	    cout<< *(nv+i);
	}
}
void swap(NhanVien *a, NhanVien *b)
{
	NhanVien c = *a;
	*a = *b;
	*b = c;
}
void SapXep_Luong(NhanVien *nv, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
			if((nv+i)->Get_Luong() < (nv+j)->Get_Luong())
				swap((nv+i), (nv+j));
	}
	Xuat_DS_NhanVien(nv, n);
}
void SapXep_NamSinh(NhanVien *nv, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
			if((nv+i)->Get_NamSinh() > (nv+j)->Get_NamSinh())
				swap((nv+i), (nv+j));
	}
	Xuat_DS_NhanVien(nv, n);
}
void ThongKe_Luong(NhanVien *nv, int n)
{  
    int SoLuong = 0;
    for(int i = 0; i < n; i++){
        float temp = (nv+i)->Get_Luong();
        if(temp < 1){
            SoLuong++;
        }
    }
    cout<<"So luong Sinh Vien canh cao: "<<SoLuong;
}
int main()
{ 
    NhanVien *nv;
    int n;
    NhanVien nv1, nv2;
    int luachon;
    while(true){    
        system("cls");
        cout<<"\n1. Nhap hai nhan vien ";
        cout<<"\n2. Xuat hai nhan vien ";
        cout<<"\n3. So Sanh diem trung binh hai nhan vien ";
        cout<<"\n4. Nhap mot Danh Sach nhan vien - MANG TINH ";
        cout<<"\n5. Xuat danh sach nhan vien - MANG TINH ";
        cout<<"\n6. Sap sep Luong giam dan - MANG TINH ";
        cout<<"\n7. Sap sep Nam Sinh tang dan - MANG TINH ";
        cout<<"\n8. So Luong Nhan Vien co Luong >= 10 trieu - MANG TINH "; 
        cout<<"\n9. Thoat";

        cout << "\nNhap lua chon: ";
		cin >> luachon;
        switch(luachon)
        {
            case 1:
            {
                cout<<"\nNhap thong tin nhan vien 1: "; cin>>nv1;
                cout<<"\nNhap thong tin nhan vien 2: "; cin>>nv2;
                break;
                
            }
            case 2:
            { 
                cout<<"\nThong tin nhan vien 1: "<<endl; cout<<nv1;
                cout<<"\nThong tin nhan vien 2: "<<endl; cout<<nv2;
                system("pause");
               
            }
            case 3:
            {   
                cout<<"\nThong tin nhan vien 1: "<<endl; cout<<nv1;
                cout<<"\nThong tin nhan vien 2: "<<endl; cout<<nv2;
                if(nv1 > nv2){
                    cout<<"\nnhan vien 1 > nhan vien 2"<<endl;
                } 
                else if(nv1 < nv2){
                    cout<<"\nnhan vien 1 < nhan vien 2"<<endl;
                }
                else{ 
                    cout<<"\nnhan vien 1 = nhan vien 2"<<endl;
                } 
                system("pause");
                break;
            }
            case 4:
            {
                cout<<"\nNhap vao so luong Nhan Vien: ";
                cin>>n;
                nv = new NhanVien[n];
                Nhap_DS_NhanVien(nv, n);
                break;
            }
            case 5:
            {
                Xuat_DS_NhanVien(nv, n);
                system("pause");
                break;
            }
            case 6:
            {
                cout<<"\nSap sep Luong giam dan"<<endl;
                SapXep_Luong(nv, n);
                system("pause");
                break;
            }
            case 7:
            {
                cout<<"\nSap sep Nam Sinh tang dan"<<endl;
                SapXep_NamSinh(nv, n);
                system("pause");
                break;
            }
            case 8:
            {
                ThongKe_Luong(nv, n);
                system("pause");
                break;
            }
            case 9:
            {
                break;
            }
            default:
            {    
                cout<<"\nLua chon khong hop le. Xin kiem tra lai!!!"<<endl;
                system("pause");
                break;
            }
                
        }
    }
    system("pause");
    return 0;
}

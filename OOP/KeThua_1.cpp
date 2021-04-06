#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class people{
private:
    string name;
    int age;
    string sex;
    string address;
public:
    people();
    ~people();
    void Nhap();
    void Xuat();
};

people::people(){
}
people::~people(){
    
}
void people::Nhap()
{
    cout<<"Nhap ten: ";
    getline(cin,name);
    cout<<"Nhap tuoi: ";
    cin >> age;
    cin.ignore(1);
    cout<<"Nhap gioi tinh: ";
    getline(cin,sex);
    cout<<"Nhap dia chi: ";
    getline(cin,address);
}
void people::Xuat()
{
    cout<<"Ten: " << name << endl;
    cout<<"Tuoi: " << age << endl;
    cout<<"Gioi tinh: " << sex << endl;
    cout<<"Dia chi: " << address << endl;
}
class student: public people{
private:
    string id;
    float math, phy, ches;
public:
    friend istream &operator>>(istream &in, student &st);
    friend ostream &operator<<(ostream &os, student &st);
    float agv();
    bool operator>(student st);
 	bool operator<(student st);
 	bool operator==(student st);
    float operator+(student st);
    friend void Seclection(student c[], int n);
};
istream &operator>>(istream &in, student &st)
{
    st.Nhap();
    cout<<"Nhap ma so sinh vien : ";
    in>>st.id;
    cout<<"Nhap diem toan: ";
    in>>st.math;
    cout<<"Nhap diem ly: ";
    in>>st.phy;
    cout<<"Nhap diem hoa: ";
    in>>st.ches;
    cin.ignore(1);
    return in;
}
float student::agv()
{
    return (math + phy + ches) / 3;
}
ostream &operator<<(ostream &os, student &st)
{
    st.Xuat();
    cout << "MSSV: " << st.id <<endl;
    cout<<"Diem toan: " << st.math <<endl;
    cout<<"Diem ly: " << st.phy <<endl;
    cout<<"Diem hoa: " << st.ches <<endl;
    cout << "Diem trung binh ba mon la: " <<  setprecision(2) << fixed << st.agv()<<endl;
    return os;
}
bool student::operator>(student st)
{
    if(this->agv()>st.agv()) return true;
    return false;
}
bool student::operator<(student st)
{
    if(this->agv()<st.agv()) return true;
    return false;
}
bool epsilon(double a, double b) //so sánh 2 số thực
{
    double eps = 0.00000001;
    if(abs(a - b) <= eps)
        return true;
    return false;
}
bool student::operator==(student st)
{
    if(epsilon(this->agv(), st.agv())) return true;
    return false;
}
float student::operator+(student st)
{
    return this->agv()+st.agv();
}
void Seclection(student c[], int n)  // sắp xếp chọn
{
    for (int i = 0; i < n-1; i++)  
    {   
        int min = i;  
        for (int j = i+1; j < n; j++)  
        if (c[j] < c[min])  
            min = j;   
        student temp = c[min];
        c[min] = c[i];
        c[i] = temp; 
    } 
    for(int i=0; i<n; i++)
    {
        cout<<"\n"<<c[i];
    } 
}
int main()
{
    int n;
    do{
        cout<<"\nNhap so luong sinh vien (>=3): ";
        cin>>n;
        cin.ignore(1);
    }while(n<3);
    student a, b, c[100];
    // XỬ LÝ CHO 2 SINH VIÊN
    // cin.ignore(1);
    // cout<<"-Thong tin sinh vien 1: \n";
    // cin>>a;
    // cout<<"\n"<<a;
    // cout<<"-Thong tin sinh vien 2: \n"; 
    // cin>>b;
    // cout<<"\n"<<b;
    // cout<<"\n-So sanh diem trung binh 2 sinh vien: ";
    // if(a>b) cout<<"\nSV1 > SV2";
    // if(a<b) cout<<"\nSV1 < SV2";
    // if(a==b) cout<<"\nSV1 = SV2";
    // cout<<"\n-Tong diem TB cua 2 sinh vien: "<< a+b;
    // XỬ LÝ CHO CẢ LỚP
    for(int i=0; i<n; i++)
    {
        cout<<"\n-Thong tin sinh vien thu "<< i+1 <<": \n";
        cin>>c[i];
        cout<<c[i];
    }
    cout<<"\n-Sap xep theo diem TB tang dan: ";
    Seclection(c, n);
    system("pause");
}
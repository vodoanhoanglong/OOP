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
    void input();
    void output();
};
class student: public people{
private:
    string id;
    float math, phy, ches;
public:
    void input();
    void output();
    float agv();
};

//People
people::people(){
}
people::~people(){
    
}
void people::input(){
    
    cout<<"Nhap ten: ";
    getline(cin,name);
    cin.ignore(0);
    cout<<"Nhap tuoi: ";
    cin >> age;
    cin.ignore(1);
    cout<<"Nhap gioi tinh: ";
    getline(cin,sex);
    cin.ignore(0);
    cout<<"Nhap dia chi: ";
    getline(cin,address);
    cin.ignore(0);
    
}
void people::output(){
    cout<<"Ten: " << name << endl;
    cout<<"Tuoi: " << age << endl;
    cout<<"Gioi tinh: " << sex << endl;
    cout<<"Dia chi: " << address << endl;
  
}
void student::input(){
    people::input();
    cout<<"Nhap ma so sinh vien : ";
    getline(cin,id);
    cin.ignore(0);
    cout<<"Nhap diem toan: ";
    cin>>math;
    cout<<"Nhap diem ly: ";
    cin>>phy;
    cout<<"Nhap diem hoa: ";
    cin>>ches;
}
void student::output(){
    cout << "MSSV: " << id <<endl;
    cout<<"Diem toan: " << math <<endl;
    cout<<"Diem ly: " << phy <<endl;
    cout<<"Diem hoa: " << ches <<endl;
    cout << "Diem trung binh ba mon la: " <<  setprecision(2) << fixed <<agv()<<endl;
}
float student::agv(){
    return (math + phy + ches) / 3;
}
int main(){
    student b;
    b.input();
    b.output();
    return 0;
}

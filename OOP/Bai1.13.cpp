#include<iostream>
#include<string>
using namespace std;

class Student 
{
    private:
        string hoten;
        float dk1, dk2, dtb;
    public:
        Student();
        void nhap();
        void xuat();
        float DiemTrungBinh();
        bool operator >(Student sv);
};

Student::Student()
{
    hoten = "";
    dk1 = 10;
    dk2 = 10;
    dtb = 10;
}
void Student::nhap()
{
    fflush(stdin);
    cout<<"\nNhap Ho Ten Student: ";
    getline(cin, hoten);
    cout<<"\nNhap Diem Ki 1: ";
    cin>>dk1;
    cout<<"\nNhap Diem Ki 2: ";
    cin>>dk2;
}
float Student::DiemTrungBinh()
{
    dtb = (dk1 + 2*dk2)/3;
    return dtb;
}

bool Student:: operator >(Student sv)
{
    if(this->dtb > sv.dtb)
        return true;
    return false;
}
void Student::xuat()
{
    cout<<"Ho Ten: "<<hoten<<endl;
    cout<<"Diem Ki 1: "<<dk1<<endl;
    cout<<"Diem Ki 2: "<<dk2<<endl;
    cout<<"Diem Trung Binh: "<<DiemTrungBinh();
}


int main()
{
    Student sv[5];
    // Nhập danh sách Student
      for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap Student thu "<<i + 1<<": "<<endl;
        sv[i].nhap();
    }

    // Xuất danh sách Student
    cout<<"\n============================"<<endl;
    cout<<"Mang Student vua nhap la: ";
    cout<<"\n============================"<<endl;
    for(int i = 0; i < 5; i++)
    {  
        cout<<"Student thu"<<i + 1<<": "; sv[i].xuat(); 
        cout<<"\n____________________________"<<endl;
    }


    // Sắp xếp danh sách Student giảm dần theo Điểm Trung Bình
	int min;
	for(int i = 0; i < 5 - 1; i++) 
	{
		min = i;
		for(int j = i + 1; j < 5; j++)
		 {
			if(sv[j].DiemTrungBinh() > sv[min].DiemTrungBinh()) 
			{
				min = j;
			}
		}	
		if(min != i)
        {
            Student temp = sv[min];
            sv[min] = sv[i];
            sv[i] = temp;
        }
	}
    
    // Xuất danh sách Student vừa sắp xếp
    cout<<"\n========================================"<<endl;
    cout<<"Mang Student sap xep giam dan DTB ca nam: ";
    cout<<"\n========================================"<<endl;
    for(int i = 0; i < 5; i++)
    {   
        cout<<"Student thu"<<i + 1<<": "; sv[i].xuat(); 
        cout<<"\n________________________________________"<<endl;
    }


    system("pause");
    return 0;
}

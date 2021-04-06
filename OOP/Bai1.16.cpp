#include<iostream>
using namespace std;
class phanso{
	private:
		int tu;
		int mau;
	public:
		phanso();
        phanso(int a, int b);
		void nhap();
		void xuat();	
        bool operator ==(phanso ps);
};
phanso::phanso()
{
	tu=0;
	mau=1;
}

phanso::phanso(int a, int b)
{
	tu=a;
	mau=b;
}        
void phanso::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
}
void phanso::xuat(){
	if(this->mau==1)
		cout<<tu<<endl;
	else
		cout<<tu<<"/"<<mau;
}
bool phanso::operator ==(phanso ps)
{
    if((this->tu == ps.tu) && (this->mau == ps.mau)) 
        return true;
    return false;
}
int main(){


    phanso ps[5], x;
    // Nhập mảng 
    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap vao Phan So thu "<<i + 1<<": "<<endl;
        ps[i].nhap();
    }
    
    // Xuất mảng Phân Số vừa nhập
    cout<<"___________________________________"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<"\nPhan So thu"<<i + 1<<": ";
        ps[i].xuat(); 
    }

    // Tìm kiếm x
    cout<<"\nNhap Phan So can tim: "; x.nhap();
    int dem = 0; //Biến đếm để biết số lần x xuất hiện trong mảng
    for(int i = 0; i < 5; i++) 
    {
        if (ps[i] == x) 
        {
            dem++;
            cout<<"Phan So "; x.xuat(); cout<<" co trong mang"<<endl; 
        } 
    }
    if(dem == 0)
        { 
            cout<<"Khong co Phan So " ; x.xuat() ; cout<<" trong mang "<<endl; 
        }

    system("pause");
    return 0;
}
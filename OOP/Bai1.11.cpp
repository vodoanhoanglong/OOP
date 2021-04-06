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
		void rutgon();
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
int UCLN(int a, int b){
	while(a != b){
		if(a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void phanso::rutgon(){
	int a=UCLN(tu,mau);
	this->tu=tu/a;
	this->mau=mau/a;
}
void phanso::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
}
void phanso::xuat(){
	rutgon();
	if(this->mau==1)
		cout<<tu<<endl;
	else
		cout<<tu<<"/"<<mau<<endl;
}

int main(){
    phanso ps[5], c;

    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap Phan So thu "<<i + 1<<": "<<endl;
        ps[i].nhap();
    }
    
    cout<<"\n_________________________________"<<endl;
    cout<<"\nPhan so sau khi rut gon: "<<endl;
     for(int i = 0; i < 5; i++)
    {
        cout<<"Phan so thu"<<i + 1<<": "; ps[i].xuat(); 
    }
    
    system("pause");
    return 0;

}
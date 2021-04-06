#include <iostream>
#include <string.h>

using namespace std;
class MH
{
private:
	char tmh[30];
	int sl;
	float dg;

public:
	int getSL();
	float getDG();
	float tien();
	void nhap();
	void xuat();
};
class HD
{
private:
	char thd[30];
	char dsmh[30];
	int slmh;
	MH *mh;

public:
	void nhap();
	void xuat();
	float tongt(float *t, int n);
	float HD_MAX();
	void Tim_Ten(HD* hd, int n);
};
int MH::getSL()
{
	return sl;
}
float MH::getDG()
{
	return dg;
}
void MH::nhap()
{
	cout << "ten mat hang: ";
	cin >> tmh;
	cout << "so luong: ";
	cin >> sl;
	cout << "don gia: ";
	cin >> dg;
}
void MH::xuat()
{
	cout << "\tTen mat hang: " << tmh << endl;
	cout << "\tSo luong: " << sl << endl;
	cout << "\tDon gia: " << dg << endl;
	cout << "-- Thanh tien: " << tien() << endl;
}
void HD::nhap()
{
	cout << "Nhap ten hoa don: ";
	cin >> thd;
	cout << "Nhap danh muc hang: ";
	cin >> dsmh;
	cout << "Nhap so luong hang: ";
	cin >> slmh;
	mh = new MH[slmh];
	for (int i = 0; i < slmh; i++)
	{
		(mh + i)->MH::nhap();
	}
}
void HD::xuat()
{
	float *a, S = 0;
	a = new float[slmh];
	cout << "Ten hoa don: " << thd << endl;
	cout << "Danh muc hang: " << dsmh << endl;
	cout << "So luong mat hang: " << slmh << endl;
	for (int i = 0; i < slmh; i++)
	{
		(mh + i)->MH::xuat();
		*(a+i) = (mh + i)->tien();
		S = S + tongt((a+i), slmh);
	}
	cout << "--> Tong tien hoa don: " << S << endl;
}
float MH::tien()
{
	return dg * sl;
}
float HD::tongt(float *t, int n)
{
	float S = 0;
	for (int i = 0; i < n; i++)
	{
		S = S + *(t + i);
	}
	return S;
}
float HD::HD_MAX()
{
	float *a;
	a = new float;
	float S = 0;
	for (int i = 0; i < slmh; i++)
	{
		*a = (mh + i)->tien();
		S = S + tongt(a, slmh);
	}
	return S;
}
void HD::Tim_Ten(HD *hd, int n)
{
	int temp = 0;
    char timten[30];
	cout<<"Nhap ten hoa don can tim: "<<endl;
	cin>>timten;
	for(int i=0; i<n; i++)
        if(strcmp(timten, (hd+i)->thd)==0)
		{
		    (hd+i)->xuat();
			temp++;
		}
	if(temp == 0) cout<<"Khong tim thay hoa don"<<endl;
}
int main()
{
	HD *hd;
	int n;
	cout << "\t\t\t\tNhap so luong hoa don: ";
	cin >> n;
	hd = new HD[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\t\t\t\tNhap thong tin hoa don thu " << i << endl;
		(hd + i)->nhap();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\t\t\t\tXuat thong tin hoa don thu " << i << ": " << endl;
		(hd + i)->xuat();
	}

	//Tim hoa don lon nhat
	cout << "\t\t\t\tHoa don co tong tien lon nhat la: " << endl;
	int temp = 0;
	float max = (hd + 0)->HD_MAX();
	for (int i = 1; i < n; i++)
	{
		if ((hd + i)->HD_MAX() > max)
		{
			max = (hd + i)->HD_MAX();
			temp = i;
		}
		(hd + temp)->xuat();
	}

    //Tim hoa don theo ten
	cout<<"\t\t\t\tTim kiem theo ten hoa don: " << endl;
   	hd->Tim_Ten(hd, n);
	system("pause");
}

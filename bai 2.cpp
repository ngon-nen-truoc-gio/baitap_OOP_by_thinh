#include<iostream>
using namespace std;
struct phanso
{
	int tu,mau;
};
struct dayphanso
{
	phanso *arr;
	int n;
};
void nhap(phanso &a)
{
	cout<<"Nhap tu so: ";cin>>a.tu;
	cout<<"\nNhap mau so: ";cin>>a.mau;
}
void xuat(phanso a)
{
	cout<<a.tu<<"/"<<a.mau;
}
void nhapmangphanso(dayphanso &day)
{
	for(int i = 0; i<day.n; i++)
	{
		cout<<"\nNhap phan so thu "<<i+1<<endl;
		nhap(day.arr[i]);
	}
}
void xuatmangphanso(dayphanso day)
{
	for (int i = 0; i < day.n; i++)
	{
		cout << "\nPhan so thu " << i + 1 << ": ";
		xuat(day.arr[i]);
	}
}
int UCLN(int x, int y)
{
	if (x < 0)
	{
		x *= -1;
	}
	if (y < 0)
	{
		y *= -1;
	}

	while (x != y)
	{
		if (x > y)
		{
			x = x - y;
		}
		else
		{
			y = y - x;
		}
	}
	return x;
}
void rutgon(phanso &a)
{
	int ucln = UCLN(a.tu, a.mau);
	a.tu = a.tu / ucln;
	a.mau = a.mau / ucln;
}

void rutgondayphanso(dayphanso &day)
{
	for (int i = 0; i < day.n; i++)
	{
		rutgon(day.arr[i]);
	}
}
phanso tinhtong(phanso a, phanso b)
{
	phanso ketqua;
	if (a.mau != b.mau)
	{
		ketqua.tu = (a.tu * b.mau) + (b.tu * a.mau);
		ketqua.mau = a.mau * b.mau;
	}
	else
	{
		ketqua.tu = a.tu + b.tu;
		ketqua.mau = a.mau;
	}
	return ketqua;
}
phanso tinhtongdayphanso(dayphanso day)
{

	phanso ketqua = day.arr[0];


	for (int i = 1; i < day.n; i++)
	{
		ketqua = tinhtong(ketqua, day.arr[i]);
	}

	return ketqua;
}
int main()
{
	dayphanso day;
	cout << "\nNhap so luong phan so: ";
	cin >> day.n;
	day.arr = new phanso[day.n]; 
	cout << "\n\n\t\t NHAP DANH SACH PHAN SO\n";
	nhapmangphanso(day);
	system("cls");
	cout << "\n\n\t\t DANH SACH PHAN SO\n";
	xuatmangphanso(day);

	cout << "\n\n\t\t DANH SACH PHAN SO SAU KHI RUT GON\n";
	rutgondayphanso(day);
	xuatmangphanso(day);

	cout << "\n\n\n\t\t TONG TAT CA CAC PHAN SO\n";
	phanso ketqua;
	ketqua = tinhtongdayphanso(day);
	rutgon(ketqua);
	xuat(ketqua);
	cout<<endl;
	return 0;

}

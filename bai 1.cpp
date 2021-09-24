#include<iostream>
#include<math.h>
using namespace std;
struct Sophuc
{
	int thuc,ao;
};
void nhap(Sophuc &a)
{
	cout<<"Nhap phan thuc: ";cin>>a.thuc;
	cout<<"\nNhap phan ao: ";cin>>a.ao;
}
void xuat(Sophuc a)
{
	cout<<a.thuc<<((a.ao>=0)? " + " :" - ")<<abs(a.ao)<<"i"<<endl;
}
void tong(Sophuc a, Sophuc b, Sophuc c)
{
	c.thuc = a.thuc + b.thuc;
	c.ao = a.ao + b.ao;
	xuat(c);
}
void hieu(Sophuc a, Sophuc b, Sophuc c)
{
	c.thuc = a.thuc - b.thuc;
	c.ao = a.ao - b.ao;
	xuat(c);
}
int main()
{
	Sophuc a,b,c;
	cout<<"So phuc a"<<endl;
	nhap(a);
	cout<<"So phuc b"<<endl;
	nhap(b);
	cout<<endl;
	cout<<"Tong hai so phuc"<<endl;
	tong(a,b,c);
	cout<<"Hieu hai so phuc"<<endl;
	hieu(a,b,c);
	
}

#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
struct hanghoa
{
	char mahang[8], tenhang[30];
	int soluong;
	float dongia, thanhtien;
};
void nhap(hanghoa a[], int n);
void xuat(hanghoa a[], int n);
void thanhtien(hanghoa a[], int n);
int main()
{
	Nocursortype();
	hanghoa a[100]; int n;
	cout<<" nhap so mat hang: ";
	cin>>n;
	nhap(a,n);
	system("cls");
	xuat(a,n);
	cout<<endl;
}
void nhap(hanghoa a[], int n)
{
	for(int i=1;i<=n;i++)
	{
		TextColor(i+7);
		cout<<"\nSTT: "<<i;
		cout<<"\nNhap ma hang: ";
		cin.ignore();
		cin.getline(a[i].mahang,8);
		cout<<"Nhap ten hang: ";
		cin.getline(a[i].tenhang,30);
		cout<<"Nhap so luong: ";
		cin>>a[i].soluong;
		cout<<"Nhap don gia: ";
		cin>>a[i].dongia;
		system("cls");
	}
}
void thanhtien(hanghoa a[], int n)
{
	for(int i=0;i<n;i++)
	{
		a[i].thanhtien=a[i].soluong*a[i].dongia;
	}
}
void xuat(hanghoa a[], int n)
{
	float max=0;int k;
	TextColor(14);
	cout<<setw(50)<<"DANH SACH NHUNG MAT HANG CO DON GIA> 50"<<endl;
	Sleep(500);
	cout<<setw(5)<<"STT"<<setw(10)<<"Ma hang"<<setw(15)<<"Ten hang"<<setw(10)<<"SL"<<setw(15)<<"Don gia"<<endl;
	Sleep(500);
	for(int i=0;i<n;i++)
	{
		if(a[i].dongia>50)
			cout<<setw(5)<<i+1<<setw(10)<<a[i].mahang<<setw(15)<<a[i].tenhang<<setw(10)<<a[i].soluong<<setw(15)<<a[i].dongia<<endl;
			Sleep(500);
	}
}

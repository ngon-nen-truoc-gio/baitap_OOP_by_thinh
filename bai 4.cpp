#include<iomanip.h>	
#include<iostream.h>
#include<windows.h>
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
struct sinhvien
{
	char tensv[30], masv[8], que[30];
	float td;
};
void nhap(sinhvien a[], int n);
void SwapNS(sinhvien a[], int n);
void queND(sinhvien a[], int n);
int main()
{
	Nocursortype();
	sinhvien a[20]; int n;
	cout<<" nhap so sinh vien: ";
	cin>>n;
	nhap(a,n);
	system("cls");
	SwapNS(a,n);
	queND(a,n);
	cout<<endl;
}
void nhap(sinhvien a[], int n)
{
	for(int i=0;i<n;i++)
	{
		TextColor(i+7);
		cout<<"\nSTT: "<<i+1;
		cout<<"\nNhap ma sinh vien: ";
		cin.ignore();
		cin.getline(a[i].masv,8);
		cout<<"\nNhap ten sinh vien: ";
		cin.getline(a[i].tensv,30);
		cout<<"\nNhap que quan cua sinh vien: ";
		cin.getline(a[i].que,30);
		cout<<"\nNhap tong diem cua sinh vien: ";
		cin>>a[i].td;
		system("cls");
	}
}

void SwapNS(sinhvien a[], int n)
{
	int temp;
	TextColor(14);
	cout<<setw(50)<<"DANH SACH SINH VIEN GIAM DAN THEO TONG DIEM"<<endl;
	Sleep(500);
	cout<<setw(5)<<"STT"<<setw(10)<<"Ma sv"<<setw(15)<<"Ten sv"<<setw(15)<<"Que quan"<<setw(15)<<"Tong diem"<<endl;
	Sleep(500);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].td>a[j].td)
				temp=a[i].td;
				a[i].td=a[j].td;
				a[j].td=temp;	
		}	
	}
	for(int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1<<setw(10)<<a[i].masv<<setw(15)<<a[i].tensv<<setw(15)<<a[i].que<<setw(15)<<a[i].td<<endl;
		Sleep(500);
	}
	cout<<endl;	
}
void queND(sinhvien a[], int n)
{
	TextColor(14);
	cout<<setw(50)<<"DANH SACH SINH VIEN QUE NAM DINH"<<endl;
	Sleep(500);
	cout<<setw(5)<<"STT"<<setw(10)<<"Ma sv"<<setw(15)<<"Ten sv"<<setw(15)<<"Que quan"<<setw(15)<<"Tong diem"<<endl;
	Sleep(500);
	for(int i=0;i<n;i++)
	{
		if(a[i].que,"nam dinh"||a[i].que,"Nam Dinh"||a[i].que,"NAM DINH")
			cout<<setw(5)<<i+1<<setw(10)<<a[i].masv<<setw(15)<<a[i].tensv<<setw(15)<<a[i].que<<setw(15)<<a[i].td<<endl;
		Sleep(500);
	}
}

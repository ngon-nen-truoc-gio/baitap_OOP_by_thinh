#include <iostream.h>
#include <iomanip.h>
#include <string.h>
struct ngaySinh{
	int ngay, thang, nam;	
};

class KH{
	private:
		char ht[30];
		ngaySinh ns;
		char cmt[10];
		char k[50];
	public:
		void nhap();
		
		void xuat();
		
		char *getHoTen(){
			return ht;
		}
		int getThang(){
			return ns.thang;
		}
};
void KH::nhap()
{
	cout<<"\nNhap vao ho ten: ";
	cin.getline(ht, 30);
	cout<<"\nNhap vao ngay sinh: ";
	cin>>ns.ngay;
	cin>>ns.thang;
	cin>>ns.nam;
	cin.ignore();
	cout<<"\nNhap vao so chung minh: ";
	cin.getline(cmt, 10);
	cout<<"\nNhap vao ho khau: ";
	cin.getline(k, 50);
}
void KH::xuat()
{
	cout<<ht
	<<setw(30)<<ns.ngay<<"/"<<ns.thang<<"/"<<ns.nam
	<<setw(15)<<cmt
	<<setw(10)<<k<<endl;
}
int main()
{
	int n;
	KH *a = new KH[n];
	do{
		cout<<"\nNhap vao so luong Khach hang: ";
		cin>>n;
		if(n < 0){
			cout<<"\nNhap lai so luong Khach hang.";
		}	
	}while(n < 0);
	cin.ignore();
	for(int i = 0; i < n; i++){
		cout<<"\nNhap vao thong tin Khach hang thu: "<<i+1<<endl;
		a[i].nhap();
	}
	for(int i = 0; i < n; i++){
		a[i].xuat();
	}
	cout<<"\nSap xep.\n";
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(strcmpi(a[i].getHoTen(), a[j].getHoTen()) > 0){
				KH temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		a[i].xuat();
	}
	
	cout<<"\nKhach hang co thang sinh 12"<<endl;
	for(int i = 0; i < n; i++){
		if(a[i].getThang() == 12){
			a[i].xuat();
		}
	}
	return 0;
}
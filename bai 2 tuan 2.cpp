#include <iostream.h>
#include <iomanip.h>
#include <string.h>

class GV{
	private:
		char ht[15];
		int t;
		char bc[15];
		char cn[15];
		float bl;
	public:
		void nhap(){
			cin.ignore();
			cout<<"\nNhap vao ho ten: ";
			cin.getline(ht, 15);
			cout<<"\nNhap vao tuoi: ";
			cin>>t;
			cin.ignore();
			cout<<"\nNhap vao bang cap: ";
			cin.getline(bc, 15);
			cout<<"\nNhap vao chuyen nganh: ";
			cin.getline(cn, 15);
			cout<<"\nNhap vao bac luong: ";
			cin>>bl;
		}
		void xuat(){
			cout<<ht
				<<setw(15)<<t
				<<setw(15)<<bc
				<<setw(15)<<cn
				<<setw(15)<<bl<<endl;
		}
		float lcb(){
			return bl * 610;
		}
		char *getChuyenNganh(){
			return cn;
		}
};

void tieude(){
	cout<<"Ho ten"
		<<setw(15)<<"Tuoi"
		<<setw(15)<<"Bang cap"
		<<setw(15)<<"Chuyen nganh"
		<<setw(15)<<"Bac luong"<<endl;
}

int main(int argc, char *argv[])
{
	int n;
	do{
		cout<<"\nNhap vao so luong Giao vien: ";
		cin>>n;
		if(n < 0){
			cout<<"\nNhap lai so luong giao vien.";
		}
	}while(n < 0);
	
	GV *a = new GV[n];
	
	for(int i = 0; i < n; i++){
		cout<<"\nNhap vao thong tin Giao vien thu: "<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"\nDanh sach Giao vien: "<<endl;
	tieude();
	for(int i = 0; i < n; i++){
		a[i].xuat();
	}
	
	cout<<"\nDanh sach Giao vien co luong nho hon 2000"<<endl;
	tieude();	
	for(int i = 0; i < n; i++){
		if(a[i].lcb() < 2000){
			a[i].xuat();			
		}
	}
	
	cout<<"\nSap xep theo chuyen nganh: "<<endl;
	tieude();
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(strcmpi(a[i].getChuyenNganh(), a[j].getChuyenNganh()	) > 0){
				GV temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		a[i].xuat();
	}	
	return 0;
}
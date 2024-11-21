#define SIZE 100
#include <stdio.h>
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n);
int tongDuong(int a[], int n);
int tongViTriLe(int a[], int n);
int demSoPhanTuAm(int a[], int n);
int demSoPhanTuLe(int a[],int n); 
int main()
{
	int A[SIZE];
	int n, kq, kq1;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);
	
	//n hop le
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	kq = tongMang(A,n);
	printf("\nTong cac gia trong mang la: %d", kq);
	//Goi ham d
	 kq = tongDuong(A, n);
    printf("\nTong cac gia tri duong trong mang la: %d", kq);
    //Goi ham cau e
    kq = tongViTriLe(A, n);
    printf("\nTong cac gia tri le trong mang la: %d", kq);
    //Goi ham cau f
     kq = demSoPhanTuAm(A, n);
    printf("\nSo luong phan tu am trong mang la: %d", kq);
    //Goi ham cau g
    kq = demSoPhanTuLe(A, n);
    printf("\nSo phan tu le trong mang la: %d", kq);
	return 0;
}
int tongMang(int a[], int n)
{
	int tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	return tong;
}

void xuatMang(int a[], int n)
{
	int i;
	for(i=0; i<=n-1; i++)
	{
		printf("%8d", a[i]);
	}
}
void nhapMang(int a[], int n)
{
	int i;
	
	i = 0;
	while(i<=n-1)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]); //a+i
		i++;
	}
}
int tongDuong(int a[], int n)
{
    int tong = 0;
    int i = 0;
    do {
        if (a[i] > 0) {  //kiem tra phan tu duong
            tong += a[i];
        }
        i++;
    } while (i < n);  

    return tong;
}
int tongViTriLe(int a[], int n)
{	
	int tong = 0;
	int i = 1;
	do {
		tong += a[i];
		i += 2;
	}while(i < n);
	return tong;
}
int demSoPhanTuAm(int a[], int n)
{
    int dem = 0;
    int i = 0;
    do {
        if (a[i] < 0) {
        	dem++;
        }
         i++;
    }while (i < n);
    return dem;
}
int demSoPhanTuLe(int a[], int n){
	int dem = 0;
	int i = 0;
	do{
		if (a[i] % 2 != 0){
			dem++;
		}i++;
	}while(i < n);
	return dem;
}


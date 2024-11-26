#include <stdio.h>	
#define SIZE 100

void nhapMang(float a[], int n);
void xuatMang(float a[], int n);
float tinhTong(float a[],int n);
float tinhTrungBinhCacPhanTuLe(float a[],int n);
int demSoPhanTuDuong(float a[], int n);
void sapXepMangTangDan(float a[], int n);
int main()
{
    float A[SIZE];
    int n;
    float  kq, kq1, kq2;
    
    do {
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &n);  
        
        if (n <= 0 || n > SIZE) {
            printf("So phan tu khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n > SIZE);  
    
    // goi ham cau a
    nhapMang(A, n);
    printf("\nMang vua nhap la: ");
    //goi ham cau b
    xuatMang(A, n);
	//goi ham cau c
    kq = tinhTong(A, n);
    printf("\nTong cac gia trong mang la: %.2f", kq);
    // goi ham cau d
    kq1 = tinhTrungBinhCacPhanTuLe(A, n);
    if (kq == -1) {
        printf("\nKhong co phan tu le trong mang.");
    } else {
        printf("\nTrung binh cong cac phan tu le trong mang la: %.2f", kq1);
    }
    // goi ham cau e
    kq2 = demSoPhanTuDuong(A, n);
    printf("\nSo phan tu duong trong mang la : %d", kq2);  
    //goi ham cau f
    sapXepMangTangDan(A, n);
    printf("\nMang sau khi sap xep tang dan: ");
    xuatMang(A, n);
    return 0;
}

void nhapMang(float a[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("\nNhap gia tri tai vi tri %d: ", i);
        scanf("%f", &a[i]);  
    }
}

void xuatMang(float a[], int n)
 {
    for (int i = 0; i < n; i++) 
	{
        printf("%8.2f ", a[i]);  
    }
    printf("\n");
}

float tinhTong(float a[], int n) 
{
    float tong = 0.0;
    for (int i = 0; i < n; i++) 
	{
        tong += a[i];
    }
    return tong;
}


float tinhTrungBinhCacPhanTuLe(float a[], int n) 
{
    float tong = 0.0;
    int dem = 0;
    
    for (int i = 1; i < n; i += 2) 
	{ 
        tong += a[i];
        dem++;
    }
    if (dem == 0) {
        return -1;  
    }
    return tong / dem;
}

int demSoPhanTuDuong(float a[], int n)
 {
    int dem = 0;
  
    for (int i = 0; i < n; i++)
	 {
        if (a[i] >= 0) 
		{ 
            dem++;
        }
    }
    return dem;
}

void sapXepMangTangDan(float a[], int n)
{
	for(int i = 0;i <= n -1;i++)
	{
		for(int j = 0;j < n -i -1;j++)
		{
			if(a[j] > a[j + 1])
			{
				float temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}		
}



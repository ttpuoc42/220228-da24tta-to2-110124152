#include<string.h>
#include<stdio.h>
struct CON_NGUOI{
	char hoten[30], diachi[100], gioitinh[4];
	int tuoi;
	float thunhap;
};
typedef struct CON_NGUOI CN;

void nhap(CN *a);
void xuat(CN a);
int main()
{
	CON_NGUOI a, b;
	
	nhap(&a);
	
	printf("\nThong tin vua nhap la: \n");
	xuat(a);
	
	return 0;
}
void xuat(CN a)
{
	printf("%s\t%d\t%s\t%s\t%f", a.hoten, a.tuoi, a.diachi, a.gioitinh, a.thunhap);
}
void nhap(CN *a)
{
	//Nhap thanh phan ho ten
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(a->hoten);
	
	//Nhap thanh phan dia chi
	printf("\nNhap vao dia chi: ");
	fflush(stdin);
	gets(a->diachi);
	
	//Nhap thanh phan gioi tinh
	printf("\nGioi tinh cua ban la: ");
	fflush(stdin);
	gets(a->gioitinh);
	
	//Nhap thanh phan tuoi
	printf("\nHay cho biet tuoi: ");
	scanf("%d", &a->tuoi);
	
	//Nhap thanh phan thu nhap
	printf("\nThu nhap cua ban la bao nhieu: ");
	scanf("%f", &a->thunhap);
}

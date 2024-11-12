#include <stdio.h>
#include <stdlib.h.>
int main()
{
	char mssv[10],hoten[20],lop[30];
	int namsinh;
	float diemxettuyen;
	
	printf("Nhap mssv: ");
	fflush(stdin);
	scanf("%s", mssv);
	
	printf("Nhap hoten: ");
	fflush(stdin);
	gets(hoten);
	
	printf("Nhap lop: ");
	fflush(stdin);
	scanf("%s", lop);
	
	printf("Nhap namsinh: ");
	fflush(stdin);
	scanf("%d", &namsinh);
	
	printf("Nhap diemxettuyen: ");
	fflush(stdin);
	scanf("%f", &diemxettuyen);
	
	system("cls");
	
	printf("MSSV: %s \n", mssv);
	printf("Ho ten: %s \n", hoten);
	printf("Lop: %s \n", lop);
	printf("Nam sinh: %d \n", namsinh);
	printf("Diem xet tuyen: %f", diemxettuyen);
	
	return 0;
}


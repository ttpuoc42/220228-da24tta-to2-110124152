#include <stdio.h>

int main()
{
	float soluong, dongia, chiphivc, doanhthu;
	
	printf("Nhap so luong hang: ");
	scanf("%f", &soluong);
	
	printf("Nhap don gia: ");
	scanf("%f", &dongia);
	
	printf("Nhap chi phi van chuyen: ");
	scanf("%f", &chiphivc);
	
	doanhthu = soluong *dongia -chiphivc;
	
	printf("Doanh thu trong ngay la: %.2f", doanhthu);
	
	return 0;
}		

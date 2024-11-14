#include <stdio.h>

int main()
{
	//khai bao cac bien
	int n, i, p = 1;
	
	//nhap xuat du lieu
	printf("Nhap n (n>0): ");
	scanf("%d", &n);
	
	//cau lenh tinh bai toan
	for(i = 1; i <= n; i++)
	{
		p *= i;
	}
	//in ket qua
	printf("Tich P(%d) = %d\n", n, p);
	return 0;
}		

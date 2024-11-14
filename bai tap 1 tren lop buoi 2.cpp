#include <stdio.h>

int main()
{
	//khai bao cac bien
	int n, i, s = 0;
	
	//nhap xuat du lieu
	printf("Nhap n (n>0): ");
	scanf("%d", &n);
	
	//cau lenh tinh bai toan
	for(i = 1; i <= n; i++)
	{
		s += i;
	}
	//in ket qua
	printf("Tong S(%d) = %d\n", n, s);
	return 0;
}		

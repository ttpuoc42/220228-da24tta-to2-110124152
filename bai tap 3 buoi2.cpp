#include <stdio.h>

int main()
{
	//khai bao bien
	int n, i;
	//nhap so n
	printf("Nhap so n(2<=n<=9): ");
	scanf("%d", &n);
	//kiem tra dieu kien
	if(2<=n && n<=9)
	{
	for(i = 1; i <= 10; i++)
		{
		printf("%d x %d = %d\n", n, i, n*i);
		}
	}
	else{
		printf("So n nhap khong hop le moi nhap lai, nhap trong khoang (2<= n <=9)\n");
	} 

	return 0;
}

#include <stdio.h>

int main()
{
	//khai bao bien
	int i, n;
	//vong lap for de in bang cuu chuong
	for(i = 2; i <= 9; i++){
	printf("Bang cuu chuong %d: \n", i);
		//vong lap for tinh va xuat bang cuu chuong
		for(n = 1; n <= 10; n++){
		printf("%d x %d = %d\n",i, n, i * n);
		}
	}
	
	return 0;
}

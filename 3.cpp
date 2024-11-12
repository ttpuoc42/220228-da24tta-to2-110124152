#include <stdio.h>

int main() { int a, b;

printf("nhap vao so nguyen thu nhat :");
scanf("%d", &a);

printf("Nhap vao so nguyen thu hai: ");
scanf("%d", &b);

if(a<b){
	printf("So nguyen nho hon la: %d ",a);
}
	else{
	printf("So nguyen nho hon la: %d ", b);
	}
return 0;

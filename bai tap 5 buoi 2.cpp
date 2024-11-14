#include <stdio.h>

int main(){
	int n, tong = 0, sodu;
	//nhap so nguyen n
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	//tinh tong cac chu so
	while(n != 0){
	sodu = n % 10;
	tong += sodu;
	n /= 10;
	}
	printf("Tong cac chu so cua %d la: %d\n", n, tong);

	return 0;
}

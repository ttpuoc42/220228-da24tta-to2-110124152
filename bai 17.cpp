#include <stdio.h>
//bai a
void in_gia_tri_tu_1_den_n(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d\n", i);// in gia tri tu 1 den n
    }
}
//bai b
void in_so_chan_den_n(int n){
	for(int i = 2; i <= n; i+=2){
	printf("%d\n", i);//viet ham va in cac so chan den n 
	}

}
//bai c
void in_so_chia_het_cho_5(int n){
	for (int i = 5; i <= n; i +=5){
	printf("%d\n", i);//viet ham va in ra cac so chia het cho 5 den n
	}
}
//bai e
int tinh_tong_1_den_n(int n){
	int tong = 0;
	for(int i = 1; i <= n; i++){
	tong += i;//viet ham va cong don cac gia tri
	}
	return tong;
}
int main(){
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);//nhap vao n
	
	int tong = tinh_tong_1_den_n(n);
	printf("Tong cac gia tri tu 1 den %d la: %d\n", n, tong);//goi ham va in ra cac gia tri
	return 0;
}         
//bai f
int tinh_tong_cac_so_le_den_n(int n){
	int tong = 0;
	for(int i = 1; i <= n; i+=2){
	tong += i;//viet ham va cong don cac gia tri
	}
	return tong;
}
int main(){
	int n;
	printf("Nhap vao n: ");
	scanf("%d", &n);//nhap vao n
	
	int tong = tinh_tong_cac_so_le_den_n(n);
	printf("Tong gia tri cac so le tu 1 den %d la: %d\n", n, tong);//goi ham va in ra cac gia tri
	return 0;
}         
	

		  	



















int main(){
	int n;
    do {
        printf("Nhap vao n (n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);//nhap vao n va kiem tra dieu kien
	in_gia_tri_tu_1_den_n(n)//goi ham
	in_so_chan_den_n(n)
	in_so_chia_het_cho_5(n)
	return 0;
}

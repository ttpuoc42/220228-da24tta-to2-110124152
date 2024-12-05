#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct PHAN_SO {
    int tuso, mauso;
}; 
    
void nhap(PHAN_SO *ps);
void xuat(PHAN_SO ps);
int gcd(int a, int b); 
void rutgon(PHAN_SO *ps); 
PHAN_SO cong(PHAN_SO ps1, PHAN_SO ps2); 
PHAN_SO tru(PHAN_SO ps1, PHAN_SO ps2); 
PHAN_SO nhan(PHAN_SO ps1, PHAN_SO ps2); 
PHAN_SO chia(PHAN_SO ps1, PHAN_SO ps2); 
     
int main()
{
	//nhap cac phan so
	PHAN_SO pso1, pso2;
	printf("Nhap phan so thu nhat\n ");
	nhap(&pso1);
	
	printf("\nNhap phan so thu hai\n ");
	nhap(&pso2);
	
	//xuat cac phan so
	printf("\nPhan so thu nhat: ");
	xuat(pso1);
	
	printf("\nPhan so thu hai: ");
	xuat(pso2);
	
	rutgon(&pso1);
    rutgon(&pso2);
	
	printf("\nPhan so thu nhat sau khi rut gon: ");
	xuat(pso1);
	printf("\nPhan so thu hai sau khi rut gon: ");
	xuat(pso2);
	
	PHAN_SO pso_cong = cong(pso1, pso2);
	printf("\nPhan so thu nhat + phan so thu hai: ");
    xuat(pso_cong);
    
    PHAN_SO pso_tru = tru(pso1, pso2);
    printf("\nPhan so thu nhat - phan so thu hai: ");
    xuat(pso_tru);
    
    PHAN_SO pso_nhan = nhan(pso1, pso2);
    printf("\nPhan so thu nhat * phan so thu hai: ");
    xuat(pso_nhan);
    
    PHAN_SO pso_chia = chia(pso1, pso2);
    printf("\nPhan so thu nhat / phan so thu hai: ");
    xuat(pso_chia);

	return 0;
}
void nhap(PHAN_SO *ps)
{
	//nhap tu so
	printf("Nhap tu so: ");
    scanf("%d", &ps->tuso);
    
    //nhap mau so
	printf("Nhap mau so: ");
	scanf("%d", &ps->mauso);

}

void xuat(PHAN_SO ps) {
    printf("%d/%d", ps.tuso, ps.mauso);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void rutgon(PHAN_SO *ps) {
    int ucln = gcd(abs(ps->tuso), abs(ps->mauso)); 
    ps->tuso /= ucln;
    ps->mauso /= ucln;
}
    
PHAN_SO cong(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    result.mauso = ps1.mauso * ps2.mauso;
    rutgon(&result); 
    return result;
}

PHAN_SO tru(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
    result.mauso = ps1.mauso * ps2.mauso;
    rutgon(&result); 
    return result;
}

PHAN_SO nhan(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuso = ps1.tuso * ps2.tuso;
    result.mauso = ps1.mauso * ps2.mauso;
    rutgon(&result); 
    return result;
}

PHAN_SO chia(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuso = ps1.tuso * ps2.mauso;
    result.mauso = ps1.mauso * ps2.tuso;
    rutgon(&result);
    return result;
}



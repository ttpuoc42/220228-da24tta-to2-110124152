#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
void ghivaotaptin(PHAN_SO *ds, int n, const char *filename);
void docTaptin(PHAN_SO *ds, int *n, const char *filename);
void hienThiDanhSachRutGon(PHAN_SO *ds, int n);
PHAN_SO timPhanSoNhoNhat(PHAN_SO *ds, int n);
int demPhanSoNhoNhat(PHAN_SO *ds, int n, PHAN_SO psMin);
void sapXepPhanSoTheoGiamDan(PHAN_SO *ds, int n);

int main() {
    int n = 0;
    PHAN_SO ds[100];

    // Ð?c d? li?u phân s? t? t?p tin
    docTaptin(ds, &n, "danhsachphanso.txt");

    // Hi?n th? danh sách phân s? sau khi rút g?n
    printf("Danh sach phan so sau khi rut gon:\n");
    hienThiDanhSachRutGon(ds, n);

    // Tìm phân s? có giá tr? nh? nh?t
    PHAN_SO minPS = timPhanSoNhoNhat(ds, n);
    printf("\nPhan so nho nhat: ");
    xuat(minPS);
    printf("\n");

    // Ð?m s? phân s? nh? nh?t
    int countMin = demPhanSoNhoNhat(ds, n, minPS);
    printf("\nSo luong phan so co gia tri nho nhat: %d\n", countMin);

    // S?p x?p phân s? theo th? t? gi?m d?n
    sapXepPhanSoTheoGiamDan(ds, n);
    printf("\nDanh sach phan so sau khi sap xep theo thu tu giam dan:\n");
    hienThiDanhSachRutGon(ds, n);

    return 0;
}

void nhap(PHAN_SO *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tuso);
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

void ghivaotaptin(PHAN_SO *ds, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo tap tin\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %d\n", ds[i].tuso, ds[i].mauso);
    }

    fclose(file);
    printf("Danh sach phan so da duoc ghi vao %s\n", filename);
}

void docTaptin(PHAN_SO *ds, int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tap tin\n");
        return;
    }

    *n = 0;
    while (fscanf(file, "%d %d", &ds[*n].tuso, &ds[*n].mauso) != EOF) {
        (*n)++;
    }

    fclose(file);
}

void hienThiDanhSachRutGon(PHAN_SO *ds, int n) {
    for (int i = 0; i < n; i++) {
        rutgon(&ds[i]);
        xuat(ds[i]);
        printf("\n");
    }
}

PHAN_SO timPhanSoNhoNhat(PHAN_SO *ds, int n) {
    PHAN_SO minPS = ds[0];
    double minVal = (double)minPS.tuso / minPS.mauso;

    for (int i = 1; i < n; i++) {
        double val = (double)ds[i].tuso / ds[i].mauso;
        if (val < minVal) {
            minPS = ds[i];
            minVal = val;
        }
    }

    return minPS;
}

int demPhanSoNhoNhat(PHAN_SO *ds, int n, PHAN_SO psMin) {
    int count = 0;
    double minVal = (double)psMin.tuso / psMin.mauso;

    for (int i = 0; i < n; i++) {
        double val = (double)ds[i].tuso / ds[i].mauso;
        if (val == minVal) {
            count++;
        }
    }

    return count;
}

void sapXepPhanSoTheoGiamDan(PHAN_SO *ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double val1 = (double)ds[i].tuso / ds[i].mauso;
            double val2 = (double)ds[j].tuso / ds[j].mauso;
            if (val1 < val2) {
                PHAN_SO temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

	

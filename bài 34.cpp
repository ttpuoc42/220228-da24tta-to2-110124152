#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia cau truc NGAY_THANG
struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

// Dinh nghia cau truc MON_HOC
struct MON_HOC {
    char ma_mon[10];  // Ma mon hoc
    float diem;       // Diem mon hoc
};

// Dinh nghia cau truc SINH_VIEN
struct SINH_VIEN {
    char mssv[15];         // Ma so sinh vien
    char hoten[100];       // Ho ten sinh vien
    struct NGAY_THANG ngaysinh; // Ngay sinh
    char gioi_tinh[10];    // Gioi tinh
    char dia_chi[200];     // Dia chi
    int somon;             // So luong mon hoc
    struct MON_HOC *mon_hoc;  // Mang cac mon hoc
};

// Dinh nghia cau truc LOP_HOC
struct LOP_HOC {
    char malop[10];
    char tenlop[20];
    int siso;
    struct SINH_VIEN *ds_sinhvien;
};

// Ham nhap thong tin ngay sinh
void nhap_ngay_thang(struct NGAY_THANG *ngay) {
    printf("Nhap ngay sinh (ngay/thang/nam): ");
    scanf("%d %d %d", &ngay->ngay, &ngay->thang, &ngay->nam);
}

// Ham nhap thong tin mon hoc
void nhap_mon_hoc(struct MON_HOC *mon_hoc) {
    printf("Nhap ma mon hoc: ");
    scanf("%s", mon_hoc->ma_mon);
    printf("Nhap diem mon hoc: ");
    scanf("%f", &mon_hoc->diem);
}

// Ham nhap thong tin sinh vien
void nhap_sinh_vien(struct SINH_VIEN *sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    getchar();  // Doc ky tu '\n' con lai sau khi nhap ma so sinh vien

    printf("Nhap ho ten sinh vien: ");
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = 0;  // Xoa ky tu '\n' o cuoi

    nhap_ngay_thang(&sv->ngaysinh);

    printf("Nhap gioi tinh (Nam/Nu): ");
    scanf("%s", sv->gioi_tinh);

    getchar();  // Doc ky tu '\n' con lai sau khi nhap gioi tinh
    printf("Nhap dia chi sinh vien: ");
    fgets(sv->dia_chi, sizeof(sv->dia_chi), stdin);
    sv->dia_chi[strcspn(sv->dia_chi, "\n")] = 0;  // Xoa ky tu '\n' o cuoi

    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->somon);

    // Cap phat bo nho dong cho mang mon hoc
    sv->mon_hoc = (struct MON_HOC *)malloc(sv->somon * sizeof(struct MON_HOC));

    // Nhap thong tin cac mon hoc
    for (int i = 0; i < sv->somon; i++) {
        printf("Mon hoc %d:\n", i + 1);
        nhap_mon_hoc(&sv->mon_hoc[i]);
    }
}

// Ham xuat thong tin sinh vien
void xuat_sinh_vien(struct SINH_VIEN sv) {
    printf("\nThong tin sinh vien:\n");
    printf("MSSV: %s\n", sv.mssv);
    printf("Ho ten: %s\n", sv.hoten);
    printf("Ngay sinh: %02d/%02d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi tinh: %s\n", sv.gioi_tinh);
    printf("Dia chi: %s\n", sv.dia_chi);
    printf("So mon hoc: %d\n", sv.somon);

    for (int i = 0; i < sv.somon; i++) {
        printf("Mon hoc %d: Ma mon %s, Diem: %.2f\n", i + 1, sv.mon_hoc[i].ma_mon, sv.mon_hoc[i].diem);
    }
}

// Ham nhap danh sach n sinh vien
void nhap_danh_sach_sinh_vien(struct SINH_VIEN *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        nhap_sinh_vien(&ds[i]);
    }
}

// Ham xuat danh sach n sinh vien
void xuat_danh_sach_sinh_vien(struct SINH_VIEN *ds, int n) {
    for (int i = 0; i < n; i++) {
        xuat_sinh_vien(ds[i]);
    }
}

// Nhap thong tin lop hoc
void nhap_lop_hoc(struct LOP_HOC *lop) {
    printf("Nhap ma lop: ");
    scanf("%s", lop->malop);

    getchar(); 

    printf("Nhap ten lop: ");
    fgets(lop->tenlop, sizeof(lop->tenlop), stdin);
    lop->tenlop[strcspn(lop->tenlop, "\n")] = 0; 

    printf("Nhap si so: ");
    scanf("%d", &lop->siso);
    
    lop->ds_sinhvien = (struct SINH_VIEN *)malloc(lop->siso * sizeof(struct SINH_VIEN));

   
    for (int i = 0; i < lop->siso; i++) {
        printf("\nNhap thong tin sinh vien %d: \n", i + 1);
        nhap_sinh_vien(&lop->ds_sinhvien[i]);
    }
}

// Xuat thong tin lop hoc
void xuat_lop_hoc(struct LOP_HOC lop){
    printf("\nThong tin lop hoc: \n");
    printf("Ma lop: %s\n", lop.malop);
    printf("Ten lop: %s\n", lop.tenlop);
    printf("Si so lop: %d\n", lop.siso);
    
    // Xuat danh sach sinh vien trong lop
    for (int i = 0; i < lop.siso; i++) {
        xuat_sinh_vien(lop.ds_sinhvien[i]);
    }
}

int main() {
    struct LOP_HOC lop;

    // Nhap thong tin lop hoc
    nhap_lop_hoc(&lop);

    // Xuat thong tin lop hoc
    xuat_lop_hoc(lop);

    
    for (int i = 0; i < lop.siso; i++) {
        free(lop.ds_sinhvien[i].mon_hoc);
    }
    free(lop.ds_sinhvien);

    return 0;
}





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

// Ham tim sinh vien theo ma so
struct SINH_VIEN* tim_sinh_vien_theo_mssv(struct SINH_VIEN *ds, int n, char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssv) == 0) {
            return &ds[i];  // Tra ve con tro den sinh vien tim thay
        }
    }
    return NULL;  // Neu khong tim thay
}

// Ham tim sinh vien theo ten
void tim_sinh_vien_theo_ten(struct SINH_VIEN *ds, int n, char *ten) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].hoten, ten) != NULL) {
            xuat_sinh_vien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ten '%s'.\n", ten);
    }
}

// Ham tim sinh vien sinh trong thang 8
void tim_sinh_vien_sinh_thang_8(struct SINH_VIEN *ds, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].ngaysinh.thang == 8) {
            xuat_sinh_vien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co sinh vien nao sinh trong thang 8.\n");
    }
}

// Ham tim sinh vien theo gioi tinh
void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN *ds, int n, char *gioi_tinh) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].gioi_tinh, gioi_tinh) != NULL) {
            xuat_sinh_vien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi gioi tinh '%s'.\n", gioi_tinh);
    }
}

// Ham tim sinh vien theo dia chi
void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN *ds, int n, char *dia_chi) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].dia_chi, dia_chi) != NULL) {
            xuat_sinh_vien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi dia chi '%s'.\n", dia_chi);
    }
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong sinh vien phai lon hon 0.\n");
        return 0;
    }

    struct SINH_VIEN *ds = (struct SINH_VIEN *)malloc(n * sizeof(struct SINH_VIEN));

    // Nhap danh sach sinh vien
    nhap_danh_sach_sinh_vien(ds, n);

    // Xuat danh sach sinh vien
    xuat_danh_sach_sinh_vien(ds, n);

    // Tim sinh vien theo ma so
    char mssv[15];
    printf("\nNhap ma so sinh vien can tim: ");
    scanf("%s", mssv);
    struct SINH_VIEN *sv = tim_sinh_vien_theo_mssv(ds, n, mssv);
    if (sv != NULL) {
        xuat_sinh_vien(*sv);
    } else {
        printf("Khong tim thay sinh vien voi ma so '%s'.\n", mssv);
    }

    // Tim sinh vien theo ten
    char ten[100];
    printf("\nNhap ten sinh vien can tim: ");
    getchar();  // Doc ky tu '\n' con lai sau khi nhap ma so
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;
    tim_sinh_vien_theo_ten(ds, n, ten);

    // Tim sinh vien sinh thang 8
    printf("\nDanh sach sinh vien sinh trong thang 8:\n");
    tim_sinh_vien_sinh_thang_8(ds, n);

    // Tim sinh vien theo gioi tinh
    char gioi_tinh[10];
    printf("\nNhap gioi tinh can tim (Nam/Nu): ");
    scanf("%s", gioi_tinh);
    tim_sinh_vien_theo_gioi_tinh(ds, n, gioi_tinh);

    // Tim sinh vien theo dia chi
    char dia_chi[200];
    printf("\nNhap dia chi can tim: ");
    getchar();  // Doc ky tu '\n' con lai sau khi nhap gioi tinh
    fgets(dia_chi, sizeof(dia_chi), stdin);
    dia_chi[strcspn(dia_chi, "\n")] = 0;
    tim_sinh_vien_theo_dia_chi(ds, n, dia_chi);

    // Giai phong bo nho
    for (int i = 0; i < n; i++) {
        free(ds[i].mon_hoc);
    }
    free(ds);

    return 0;
}
















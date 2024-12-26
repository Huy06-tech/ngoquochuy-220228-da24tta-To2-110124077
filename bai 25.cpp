#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MON_HOC 10
#define MAX_SINH_VIEN 100
#define MAX_TEN 100
#define MAX_DIA_CHI 200
#define MAX_GIOI_TINH 10


struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};


struct MON_HOC {
    char ma_mon[10];
    float diem;
};


struct SINH_VIEN {
    char mssv[10];
    char hoten[MAX_TEN];
    struct NGAY_THANG ngaysinh;
    char gioi_tinh[MAX_GIOI_TINH];
    char dia_chi[MAX_DIA_CHI];
    int somon;
    struct MON_HOC mon_hoc[MAX_MON_HOC];
};


void nhap_sinh_vien(struct SINH_VIEN *sv);
void xuat_sinh_vien(struct SINH_VIEN sv);
void nhap_danh_sach_sinh_vien(struct SINH_VIEN *dssv, int n);
void xuat_danh_sach_sinh_vien(struct SINH_VIEN *dssv, int n);
struct SINH_VIEN* tim_sinh_vien_theo_mssv(struct SINH_VIEN *dssv, int n, char *mssv);
void tim_sinh_vien_theo_ten(struct SINH_VIEN *dssv, int n, char *ten);
void tim_sinh_vien_thang_8(struct SINH_VIEN *dssv, int n);
void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN *dssv, int n, char *gioi_tinh);
void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN *dssv, int n, char *dia_chi);

int main() {
    struct SINH_VIEN dssv[MAX_SINH_VIEN];
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    nhap_danh_sach_sinh_vien(dssv, n);
    xuat_danh_sach_sinh_vien(dssv, n);

    
    char mssv[10];
    printf("Nhap MSSV can tim: ");
    scanf("%s", mssv);
    struct SINH_VIEN *sv = tim_sinh_vien_theo_mssv(dssv, n, mssv);
    if (sv != NULL) {
        printf("Sinh vien tim thay:\n");
        xuat_sinh_vien(*sv);
    } else {
        printf("Khong tim thay sinh vien voi MSSV %s\n", mssv);
    }

    
    char ten[MAX_TEN];
    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]", ten);
    tim_sinh_vien_theo_ten(dssv, n, ten);

    printf("Danh sach sinh vien sinh trong thang 8:\n");
    tim_sinh_vien_thang_8(dssv, n);


    char gioi_tinh[MAX_GIOI_TINH];
    printf("Nhap gioi tinh can tim: ");
    fflush(stdin);
    gets(gioi_tinh);
    printf("Danh sach sinh vien theo gioi tinh %s:\n", gioi_tinh);
    tim_sinh_vien_theo_gioi_tinh(dssv, n, gioi_tinh);

 
    char dia_chi[MAX_DIA_CHI];
    printf("Nhap dia chi can tim: ");
    scanf(" %[^\n]", dia_chi);
    printf("Danh sach sinh vien theo dia chi '%s':\n", dia_chi);
    tim_sinh_vien_theo_dia_chi(dssv, n, dia_chi);

    return 0;
}

void nhap_sinh_vien(struct SINH_VIEN *sv) {
    printf("Nhap MSSV: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]", sv->hoten);
    printf("Nhap ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
    printf("Nhap gioi tinh: ");
    fflush(stdin);
    gets(sv->gioi_tinh);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", sv->dia_chi);
    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->somon);
    for (int i = 0; i < sv->somon; i++) {
        printf("Nhap ma mon hoc %d: ", i + 1);
        scanf("%s", sv->mon_hoc[i].ma_mon);
        printf("Nhap diem mon hoc %d: ", i + 1);
        scanf("%f", &sv->mon_hoc[i].diem);
    }
}

void xuat_sinh_vien(struct SINH_VIEN sv) {
    printf("MSSV: %s\n", sv.mssv);
    printf("Ho ten: %s\n", sv.hoten);
    printf("Ngay sinh: %02d/%02d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi tinh: %s\n", sv.gioi_tinh);
    printf("Dia chi: %s\n", sv.dia_chi);
    printf("So mon hoc: %d\n", sv.somon);
    for (int i = 0; i < sv.somon; i++) {
        printf("Mon hoc %d: %s, Diem: %.2f\n", i + 1, sv.mon_hoc[i].ma_mon, sv.mon_hoc[i].diem);
    }
}

void nhap_danh_sach_sinh_vien(struct SINH_VIEN *dssv, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien %d:\n", i + 1);
        nhap_sinh_vien(&dssv[i]);
    }
}

void xuat_danh_sach_sinh_vien(struct SINH_VIEN *dssv, int n) {
    for (int i = 0; i < n; i++) {
        printf("Thong tin sinh vien %d:\n", i + 1);
        xuat_sinh_vien(dssv[i]);
    }
}

struct SINH_VIEN* tim_sinh_vien_theo_mssv(struct SINH_VIEN *dssv, int n, char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(dssv[i].mssv, mssv) == 0) {
            return &dssv[i];
        }
    }
    return NULL;
}

void tim_sinh_vien_theo_ten(struct SINH_VIEN *dssv, int n, char *ten) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(dssv[i].hoten, ten) != NULL) {
            xuat_sinh_vien(dssv[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ten '%s'\n", ten);
    }
}

void tim_sinh_vien_thang_8(struct SINH_VIEN *dssv, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (dssv[i].ngaysinh.thang == 8) {
            xuat_sinh_vien(dssv[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien sinh trong thang 8\n");
    }
}

void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN *dssv, int n, char *gioi_tinh) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(dssv[i].gioi_tinh, gioi_tinh) == 0) {
            xuat_sinh_vien(dssv[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien theo gioi tinh '%s'\n", gioi_tinh);
    }
}

void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN *dssv, int n, char *dia_chi) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(dssv[i].dia_chi, dia_chi) != NULL) {
            xuat_sinh_vien(dssv[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien theo dia chi '%s'\n", dia_chi);
    }
} 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SP 100
#define MAX_TEN_SP 100

typedef struct {
    int ngay;
    int thang;
    int nam;
} NGAY_THANG;

typedef struct {
    char maSP[20];
    char tenSP[MAX_TEN_SP];
    float donGia;
    NGAY_THANG ngaySX;
    float thoiGianSuDung;
} SAN_PHAM;

void nhapSanPham(SAN_PHAM *sp) {
    printf("\nNhap ma san pham: ");
    scanf("%s", sp->maSP);
    printf("\nNhap ten san pham: ");
    getchar(); 
    fgets(sp->tenSP, MAX_TEN_SP, stdin);
    sp->tenSP[strcspn(sp->tenSP, "\n")] = 0; 
    printf("\nNhap don gia: ");
    scanf("%f", &sp->donGia);
    printf("\nNhap ngay san xuat (ngay thang nam): ");
    scanf("%d %d %d", &sp->ngaySX.ngay, &sp->ngaySX.thang, &sp->ngaySX.nam);
    printf("\nNhap thoi gian su dung: ");
    scanf("%f", &sp->thoiGianSuDung);
}

void ghiDanhSachSanPham(SAN_PHAM *danhSach, int n) {
    FILE *file = fopen("sanpham.dat", "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fwrite(danhSach, sizeof(SAN_PHAM), n, file);
    fclose(file);
}

void hienThiDanhSachSanPham(SAN_PHAM *danhSach, int n) {
    printf("Danh sach san pham:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma SP: %s, Ten SP: %s, Don Gia: %.2f, Ngay SX: %02d/%02d/%04d, Thoi Gian SD: %.2f nam\n",
               danhSach[i].maSP, danhSach[i].tenSP, danhSach[i].donGia,
               danhSach[i].ngaySX.ngay, danhSach[i].ngaySX.thang, danhSach[i].ngaySX.nam,
               danhSach[i].thoiGianSuDung);
    }
}

SAN_PHAM* timKiemTheoMa(SAN_PHAM *danhSach, int n, const char *maSP) {
    for (int i = 0; i < n; i++) {
        if (strcmp(danhSach[i].maSP, maSP) == 0) {
            return &danhSach[i];
        }
    }
    return NULL;
}

void timKiemTheoTen(SAN_PHAM *danhSach, int n, const char *tenSP) {
    printf("San pham tim duoc:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(danhSach[i].tenSP, tenSP) == 0) {
            printf("Ma SP: %s, Ten SP: %s, Don Gia: %.2f, Ngay SX: %02d/%02d/%04d, Thoi Gian SD: %.2f nam\n",
                   danhSach[i].maSP, danhSach[i].tenSP, danhSach[i].donGia,
                   danhSach[i].ngaySX.ngay, danhSach[i].ngaySX.thang, danhSach[i].ngaySX.nam,
                   danhSach[i].thoiGianSuDung);
        }
    }
}

void timKiemTheoNamSX(SAN_PHAM *danhSach, int n, int nam) {
    printf("San pham san xuat nam %d:\n", nam);
    for (int i = 0; i < n; i++) {
        if (danhSach[i].ngaySX.nam == nam) {
            printf("Ma SP: %s, Ten SP: %s, Don Gia: %.2f, Ngay SX: %02d/%02d/%04d, Thoi Gian SD: %.2f nam\n",
                   danhSach[i].maSP, danhSach[i].tenSP, danhSach[i].donGia,
                   danhSach[i ].ngaySX.ngay, danhSach[i].ngaySX.thang, danhSach[i].ngaySX.nam,
                   danhSach[i].thoiGianSuDung);
        }
    }
}

int soSanh(const void *a, const void *b) {
    SAN_PHAM *spA = (SAN_PHAM *)a;
    SAN_PHAM *spB = (SAN_PHAM *)b;
    return (spB->donGia > spA->donGia) ? 1 : -1;
}

void sapXepTheoDonGia(SAN_PHAM *danhSach, int n) {
    qsort(danhSach, n, sizeof(SAN_PHAM), soSanh);
}

int main() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);

    SAN_PHAM danhSach[MAX_SP];
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        nhapSanPham(&danhSach[i]);
    }

    ghiDanhSachSanPham(danhSach, n);

    FILE *file = fopen("sanpham.dat", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }
    fread(danhSach, sizeof(SAN_PHAM), n, file);
    fclose(file);

    hienThiDanhSachSanPham(danhSach, n);

    char maTimKiem[20];
    printf("Nhap ma san pham can tim: ");
    scanf("%s", maTimKiem);
    SAN_PHAM *spTimThay = timKiemTheoMa(danhSach, n, maTimKiem);
    if (spTimThay) {
        printf("San pham tim thay:\n");
        printf("Ma SP: %s, Ten SP: %s, Don Gia: %.2f, Ngay SX: %02d/%02d/%04d, Thoi Gian SD: %.2f nam\n",
               spTimThay->maSP, spTimThay->tenSP, spTimThay->donGia,
               spTimThay->ngaySX.ngay, spTimThay->ngaySX.thang, spTimThay->ngaySX.nam,
               spTimThay->thoiGianSuDung);
    } else {
        printf("Khong tim thay san pham.\n");
    }

    char tenTimKiem[MAX_TEN_SP];
    printf("Nhap ten san pham can tim: ");
    getchar();
    fgets(tenTimKiem, MAX_TEN_SP, stdin);
    tenTimKiem[strcspn(tenTimKiem, "\n")] = 0;
    timKiemTheoTen(danhSach, n, tenTimKiem);

    int namTimKiem;
    printf("Nhap nam san xuat can tim: ");
    scanf("%d", &namTimKiem);
    timKiemTheoNamSX(danhSach, n, namTimKiem);

    sapXepTheoDonGia(danhSach, n);
    printf("Danh sach san pham sau khi sap xep theo don gia:\n");
    hienThiDanhSachSanPham(danhSach, n);

    return 0;
}

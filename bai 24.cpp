#include <stdio.h>

typedef struct {
    int tu; 
    int mau; 
} PHAN_SO;


void nhapPhanSo(PHAN_SO *ps);
void xuatPhanSo(PHAN_SO ps);
PHAN_SO rutGonPhanSo(PHAN_SO ps);
PHAN_SO congPhanSo(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO truPhanSo(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO nhanPhanSo(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO chiaPhanSo(PHAN_SO ps1, PHAN_SO ps2);
int gcd(int a, int b); 

int main() {
    PHAN_SO ps1, ps2, psTong, psHieu, psTich, psThuong;

    printf("Nhap phan so 1:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so 2:\n");
    nhapPhanSo(&ps2);

    printf("Phan so 1: ");
    xuatPhanSo(ps1);
    printf("\nPhan so 2: ");
    xuatPhanSo(ps2);
    
    psTong = congPhanSo(ps1, ps2);
    printf("\nTong hai phan so: ");
    xuatPhanSo(psTong);
    
    psHieu = truPhanSo(ps1, ps2);
    printf("\nHieu hai phan so: ");
    xuatPhanSo(psHieu);
    
    psTich = nhanPhanSo(ps1, ps2);
    printf("\nTich hai phan so: ");
    xuatPhanSo(psTich);
    
    psThuong = chiaPhanSo(ps1, ps2);
    printf("\nThuong hai phan so: ");
    xuatPhanSo(psThuong);
    
    return 0;
}


void nhapPhanSo(PHAN_SO *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
    } while (ps->mau == 0);
}

void xuatPhanSo(PHAN_SO ps) {
    printf("%d/%d", ps.tu, ps.mau);
}


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


PHAN_SO rutGonPhanSo(PHAN_SO ps) {
    int ucln = gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    return ps;
}


PHAN_SO congPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO psTong;
    psTong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    psTong.mau = ps1.mau * ps2.mau;
    return rutGonPhanSo(psTong);
}


PHAN_SO truPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO psHieu;
    psHieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    psHieu.mau = ps1.mau * ps2.mau;
    return rutGonPhanSo(psHieu);
}


PHAN_SO nhanPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO psTich;
    psTich.tu = ps1.tu * ps2.tu;
    psTich.mau = ps1.mau * ps2.mau;
    return rutGonPhanSo(psTich);
}


PHAN_SO chiaPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO psThuong;
    psThuong.tu = ps1.tu * ps2.mau;
    psThuong.mau = ps1 .tu * ps2.mau;
    return rutGonPhanSo(psThuong);
}

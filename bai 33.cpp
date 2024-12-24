#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu; 
    int mau; 
} PHAN_SO;


void nhapPhanSo(PHAN_SO *ps);
void xuatPhanSo(PHAN_SO ps);
PHAN_SO rutGonPhanSo(PHAN_SO ps);
void ghiPhanSoVaoFile(const char *filename, PHAN_SO *ps, int n);
void docPhanSoTuFile(const char *filename, PHAN_SO **ps, int *n);
void hienThiPhanSo(PHAN_SO *ps, int n);
PHAN_SO timPhanSoNhoNhat(PHAN_SO *ps, int n);
int demPhanSoNhoNhat(PHAN_SO *ps, int n, PHAN_SO min);
void sapXepPhanSo(PHAN_SO *ps, int n);
int gcd(int a, int b); 

int main() {
    int n;
    printf("Nhap so luong phan so (n > 0): ");
    scanf("%d", &n);
    
    PHAN_SO *ps = (PHAN_SO *)malloc(n * sizeof(PHAN_SO));
    

    for (int i = 0; i < n; i++) {
        printf("Nhap phan so %d:\n", i + 1);
        nhapPhanSo(&ps[i]);
    }
    
    
    ghiPhanSoVaoFile("phan_so.txt", ps, n);
    
    
    PHAN_SO *psDoc;
    int nDoc;
    docPhanSoTuFile("phan_so.txt", &psDoc, &nDoc);
    
 
    printf("\nDanh sach phan so sau khi rut gon:\n");
    hienThiPhanSo(psDoc, nDoc);
    
    
    PHAN_SO min = timPhanSoNhoNhat(psDoc, nDoc);
    printf("\nPhan so nho nhat: ");
    xuatPhanSo(min);
    
  
    int countMin = demPhanSoNhoNhat(psDoc, nDoc, min);
    printf("\nSo phan so nho nhat: %d\n", countMin);
    
    
    sapXepPhanSo(psDoc, nDoc);
    printf("\nDanh sach phan so sau khi sap xep:\n");
    hienThiPhanSo(psDoc, nDoc);
    
  
    free(ps);
    free(psDoc);
    
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


void ghiPhanSoVaoFile(const char *filename, PHAN_SO *ps, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %d\n", ps[i].tu, ps[i] .mau);
    }
    fclose(file);
}


void docPhanSoTuFile(const char *filename, PHAN_SO **ps, int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
printf("Khong the mo file de doc.\n");
        return;
    }
    *n = 0;
    *ps = (PHAN_SO *)malloc(sizeof(PHAN_SO) * 100);
    while (fscanf(file, "%d %d", &(*ps)[*n].tu, &(*ps)[*n].mau) == 2) {
        (*ps)[*n] = rutGonPhanSo((*ps)[*n]); 
        (*n)++;
    }
    fclose(file);
}


void hienThiPhanSo(PHAN_SO *ps, int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(ps[i]);
        printf("\n");
    }
}


PHAN_SO timPhanSoNhoNhat(PHAN_SO *ps, int n) {
    PHAN_SO min = ps[0];
    for (int i = 1; i < n; i++) {
        if ((float)ps[i].tu / ps[i].mau < (float)min.tu / min.mau) {
            min = ps[i];
        }
    }
    return min;
}


int demPhanSoNhoNhat(PHAN_SO *ps, int n, PHAN_SO min) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ps[i].tu == min.tu && ps[i].mau == min.mau) {
            count++;
        }
    }
    return count;
}


void sapXepPhanSo(PHAN_SO *ps, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)ps[i].tu / ps[i].mau < (float)ps[j].tu / ps[j].mau) {
                PHAN_SO temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }
}

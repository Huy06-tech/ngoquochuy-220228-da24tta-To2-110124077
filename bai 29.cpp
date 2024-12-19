#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int *p;
    int n;
    char duongDan[100];
    FILE *file;

    printf("Nhap duong dan tap tin: ");
    scanf("%s", duongDan);

    
    file = fopen(duongDan, "r");

   
    if (file == NULL) {
        printf("Khong the mo tap tin!\n");
        exit(1);
    }

   
    fscanf(file, "%d", &n);
    p = (int*)malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &p[i]);
    }
    fclose(file);

    
    printf("Danh sach cac gia tri vua doc ra man hinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    
    free(p);

    
    printf("Ket qua doc file tai vi tri luu tru:\n");
    printf("Duong dan tap tin: %s\n", duongDan);

    return 0;
}

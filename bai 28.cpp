#include <stdio.h>
#include <stdlib.h>

int main() {
  
    int mang[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int soPhanTu = sizeof(mang) / sizeof(mang[0]);
    char duongDan[100];
    FILE *file;

    printf("Nhap duong dan tap tin: ");
    scanf("%s", duongDan);

 
    file = fopen(duongDan, "w");

  
    if (file == NULL) {
        printf("Khong the mo tap tin!\n");
        exit(1);
    }

  
    fprintf(file, "%d\n", soPhanTu);
    for (int i = 0; i < soPhanTu; i++) {
        fprintf(file, "%d", mang[i]);
        if (i < soPhanTu - 1) {
            fprintf(file, "  ");
        }
    }
    fclose(file);

    printf("Da ghi mang vao tap tin thanh cong!\n");

  
    printf("Ket qua ghi file:\n");
    printf("Duong dan tap tin: %d");
}

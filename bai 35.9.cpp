#include"stdio.h"
#include"alloc.h"
int tong_mang(int a*,int n);
void main(){
	int a*=(int *)malloc(sizeof(int)*6);
	for(int i=0;i<6,i++){
		printf("\nNhap so nguyen thu %d: ",i+1);
		scanf("%d",a+1);
	}
	printf("Tong mang: %d",tong_mang(a,6));
}
int tong_mang(int *a, int n){
	if(n<1) return 0;
	return tong_mang(a, n-1)+*(a+(n-1));
}

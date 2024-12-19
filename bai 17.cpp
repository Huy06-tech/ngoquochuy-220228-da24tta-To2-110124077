#include <stdio.h>
#include <math.h>
#define ll long long
int is_prime(int);
void cau_a(int),cau_b(int),cau_c(int n),cau_d(int n);
ll cau_e(int),cau_f(int),cau_g(int);
double cau_h(int),cau_i(int);
int main(){
	int n;
	do{
	     printf("nhap n=");
	     scanf("%d",&n);
    }while(n>=100||n<=0);
    printf("cac gia tri tu 1 den %d: ",n);
    cau_a(n);printf("\n");
    printf("cac gia tri chan tu 1 den %d: ",n);
    cau_b(n);printf("\n");
    printf("cac gia tri chia het cho 5 tu 1 den %d: ",n);
    cau_c(n);printf("\n");
    printf("so nguyen to nho hon %d la: ",n);
    cau_d(n);printf("\n");
    printf("tong cac gia tri tu 1 den %d=%11d\n",n,cau_e(n));
    printf("tong cac so le tu 1 den %d=%11d\n",n,cau_f(n));
    printf("tong cac so nguyen to nho hon %d=11%\n",n,cau_g(n));
    printf("trung binh cong cac so le tu 1 den %d=%.21f\n",n,cau_h(n));
    printf("trung binh cong cac so nguyen to nho hon %d=%.21f\n",n,cau_i(n));
    return 0;
}
//ham kiem tra mot so co phai la so nguyen hay khong
int is_prime(int n){
    if (n<2) return 0;
	for (int i=2;i<=sprt(n);i++){
		
	} 
	return 1;
}
//cau_a: in ra cac so tu 1 den n
void cau_a(int n){
    for (int i=1;i<=n,i++){
    	printf("%d",i);
    }
}
//cau_b: in ra cac so chan tu 1 den n
void cau_b(int n){
    for (int i=2;i<=n/2*2;i+=2){
    	printf("%d",i);
    }
}
//cau_c: in ra cac so chia het cho 5 tu 1 den n
void cau_c(int n){
    for (int i=5;i<=n/5*5;i+=5){
    	printf("%d",i);
    }
}
//cau_d: in ra cac so nguyen to nho hon n
void cau_f(int n){
    for (int i=2;i<n;i++){
    	if (is_prime(i)) printf ("%d",i);
    }
}
//cau_e: tinh tong cac gia tri tu 1 den n
ll cau_e(int n){
	return 1ll*(n+1)*n/2;
}
//cau_f: tinh tong cac so le tu 1 den n
ll cau_f(int n){
    ll tong=0;
    if (n%2==0){
    	n--;
    }
    for (int i=1;i<=n;i+=2){
    	tong+=i;
    }
    return tong;
}
//cau_g: tinh tong cac so nguyen to nho hon n
ll cau_g(int n){
	ll tong=0;
	for (int i=2;i<n;i++){
		if(is_prime(i)){
			tong+=i;
		}
	}
	return tong;
}
//cau_h: tinh tong trung binh cong cac so nguyen tu 1 den n
double cau_h(int n){
	ll tongsole=cau_f(n);
	ll dem=0;
	for (int i=1;i<=n;i++){
		if (i%2!=0){
			dem++;
		}
	}
	return tongsole/dem;
}
//cau_i: tinh trung binh cong cac so nguyen to nho hon n
double cau_i(int n){
	ll tongnguyento=cau_g(n);
	lldemngto=0;
	for (int i=2;i<n;i++){
		if(is_prime(i)) demngto++;
	}
	return tongnguyento/demngto;
}
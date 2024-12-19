#define SIZE 100
#include <stdio.h>
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n);
int tongduongMang(int a[], int n);
int tongleMang(int a[], int n);
int HamdemamMang(int a[],int n);
int HamdemleMang(int a[],int n);
int Kiemtrasonguyento(int n);
int Demnguyento(int a[],int n);
int Timsonguyentodau(int a[],int n);
int main()
{
	int A[SIZE];
	int n, kq,kqduong;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);
	
	//n hop le
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	kq = tongMang(A,n);
	printf("\nTong cac gia trong mang la %d", kq);
	    kq=tongduongMang(A,n);
	    printf("\nTong duong cac gia trong mang la %d", kq);
	    kq=tongleMang(A,n);
	    printf("\nTong le cac gia trong mang la %d", kq);
	    int Dem=HamdemamMang(A,n);
	    printf("\nso phan tu am la:%d", Dem);
	    Dem=HamdemleMang(A,n);
	    printf("\nso phan tu le la:%d", Dem);
	    Dem=Demnguyento(A,n);
	    printf("\nso luong nguyen to la:%d", Dem);
	   
	    if (Timsonguyentodau(A,n)==0){
	    	printf("mang khong co so nguyen to nao");
	    }
	   	else{
	   		printf("\n so nguyen to dau la:%d", Timsonguyentodau(A,n));
	   	} 
	return 0;
}
int tongMang(int a[], int n)
{
	int tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	return tong;
}

void xuatMang(int a[], int n)
{
	int i;
	for(i=0; i<=n-1; i++)
	{
		printf("%8d", a[i]);
	}
}
void nhapMang(int a[], int n)
{
	int i;
	
	i = 0;
	while(i<=n-1)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]); //a+i
		i++;
	}
}
int tongduongMang(int a[],int n){
	int Tong = 0;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			continue;
		}

			Tong+=a[i];
			
	}
	return Tong;
}
int tongleMang(int a[], int n){
    int Tong=0;
    int i;
    for(i=0;i<n;i++)
	{
		if(a[i] % 2 !=0)
		{
		Tong+=a[i];	
		}
	} 
	return Tong; 

}
int HamdemamMang(int a[],int n)
{
	int i;
	int Dem=0;
	for (i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			Dem++;
		}
	}
	return Dem;
}
int HamdemleMang(int a[],int n)
{
	int i,Dem=0;
	for(i=0;i<n;i++)
	{
		if(a[i]%2!=0){
			Dem++;
		}
	}
	return Dem;
}
int Kiemtrasonguyento(int n){
	int i;
	if(n<=1){
		return 0;
	}

    for(i=2;i*i<n;i++){
    	if(n%i==0){
    		return 0;
    	}
    }
    return 1;
}



int Demnguyento(int a[],int n)
{
	int i,Dem=0;
	for (i=0;i<n;i++){
		if (Kiemtrasonguyento(a[i])){
			Dem++;
		}
	}
	 return Dem;    
}
int Timsonguyentodau(int a[],int n)
{
	for (int i=0; i<n;i++){
		if (Kiemtrasonguyento(a[i])){
			return a[i];
		}
	}
	return 0;
}


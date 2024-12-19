#include<stdio.h>
#define COL 100
#define ROW 100
void nhapmang(int a[][100],int m,int n);
void xuatmang(int a[][100],int m,int n);
int tongmang(int a[][100],int m,int n), tongdong(int a[][100],int m,int n,int k), tongcot(int a[][100],int m,int n,int k);
void kiemtrasoam(int a[][100],int m,int n,int k);
int kiemtrasonguyento(int n);
void kiemtracotnguyento(int a[][100],int m,int n,int k);
void sapxep(int a[][100],int m,int n,int k);
int main()
{
	int m,n,k=1;//m hang n cot
	int a[100][100];
	printf("moi nhap so hang cot: ");
	do
	{
		scanf("%d %d",&m,&n);
	}while(n<=0||n>COL||m<=0||m>ROW);
	nhapmang(a,m,n);
	xuatmang(a,m,n);
	tongmang(a,m,n);
	printf("\nTong = %d",tongmang(a,m,n));
	tongdong(a,m,n,k);
	printf ("\nNhap chi so dong k de tinh tong dong");
	scanf("%d", &k);
	printf("\nTong dong k= %d", tongdong(a,m,n,k));
	printf("\nNhap chi soi cot k de tinh tong cot");
	scanf("%d", &k);
	printf("\nTong cot k= %d", tongcot(a,m,n,k));
	kiemtrasoam(a,m,n,k);
	kiemtracotnguyento(a,m,n,k);
	return 0;
}
void nhapmang(int a[][100], int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}
void xuatmang(int a[][100],int m, int n)
{
	printf("mang vua nhap la: \n");
	for(int i=0;i<m;i++)
	{
			for(int j=0;j<n;j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\n");	
	}
}
int tongmang(int a[][100],int m,int n)
{
	int Tong=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			Tong+=a[i][j];
		}
    }
    return Tong;
}
int tongdong(int a[][100],int m,int n,int k)
{
	if(k<0||k>=m)
	{
		printf("dong k khong hop le");
		return -1;
	}
	int Tong=0;
	for(int i=0;i<n;i++)
	{
		Tong+=a[k][i];
	}
	return Tong;
}
int tongcot(int a[][100],int m,int n,int k)
{
	if(k<0||k>=n)
	{
		printf("cot k khong hop le");
		return -1;
	}
	int Tong=0;
	for(int i=0;i<n;i++)
	{
		Tong+=a[i][k];
	}
	return Tong;
}
void kiemtrasoam(int a[][100],int m,int n,int k)
{
	int check=0;
    for(int i=0;i<n;i++)
    {
    	if(a[k][i]<0)
    	{
    		check=1;
    	}
    }
    if(check==1)
    {
    	printf("\n dong k co so am");
    	
    }else
         {
         	printf("\n dong k khong co so am");
         }
}
int kiemtranguyento(int n)
{
	if(n < 2 )
	{
		return 0;
	}
	for(int i=2;i*i<=n;i++)
	{
		
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
void kiemtracotnguyento(int a[][100],int m,int n,int k)
{
	int check=0;
	for(int i=0;i<m;i++)
	{
		if(kiemtranguyento(a[i][k]))
		{
			check=1;
			break;
		}
	}
	if(check==1)
	{
		printf("\nCot k co so nguyen to");
	}
	else
	    {
	    	printf("\nCot k khong co so nguyen to");
	    }
}
void sapxep(int a[][100],int m,int n,int k )
{
	for(int i=0;i<m;i++)
	{
		for(int j=n-1;j>i;j--){
			if (a[k][j]>a[k][i]){
				int t=a[k][j];
				a[k][j]=a[k][i];
				a[k][i]=t;
			}
		}
	}
	printf("mang sau khi da sap xep dong K=%d theo gia tri giam dan: \n",k+1);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}
void timgiatrimax(int a[][100],int m,int n,int k )
{
	int max=a[k][0];
	for(int j=0;j<m;j++)
	{
		if(a[k][j]>max)
		{
			max=a[k][j];
		}
	}
}

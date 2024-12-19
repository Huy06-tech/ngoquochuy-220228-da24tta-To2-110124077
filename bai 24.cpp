#include<stdio.h>
#include<string.h>
struct PHAN_SO{
     int tu;
     int mau;
};
typedef struct PHAN_SO ps;
void nhap(PHAN_SO *ps);
void xuat(PHAN_SO ps);
int ULCN(int a,int b);
void xuatphanso(PHAN_SO *ps);
int cong(PHAN_SO *ps);
int main()
{
    PHAN_SO a, b;
    printf("nhap phan so thu nhat: ");
    nhap(&a);
    printf("\nnhap phan so thu hai: ");
    nhap(&b);
    printf("\nPhan so vua nhap la: ");
    xuat(a);
    printf("\nPhan so 1 toi gian: ");
    xuatphanso(&a);
    printf("\nPhan so 2 toi gian: ");
    xuatphanso(&b);
	return 0;
}
void xuat(PHAN_SO ps)
{
	printf("%d/%d\n", ps.tu, ps.mau);
}
void nhap(PHAN_SO *ps)
{
	do{
		printf("\nNhap tu: ");
		scanf("%d",&ps->tu);
		printf("\nNhap mau: ");
		scanf("%d",&ps->mau);
		if(ps->mau==0)
		{
			printf("\nNhap lai mau lon hon 0\n");
		}
	}while(ps->mau==0);
}
int ULCN(int a, int b)
{
	while(b!=0)
	{
		int T=a%b;
		a=b;
		b=T;
	}
	return 0;
}
void xuatphanso(PHAN_SO *ps)
{
	int ulcn=ULCN(ps->tu, ps->mau);
	ps->tu/=ulcn;
	ps->mau/=ulcn;
	if(ps->mau==0)
	{
		ps->tu==ps->tu;
		ps->mau==ps->mau;
	}
	printf("%d%d",ps->tu,ps->mau);
}

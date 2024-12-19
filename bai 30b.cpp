#include<stdio.h>
main()
{
	int a[3][3]={{1,2,-3},{4,-5,6},{-7,8,9}};
	int m=3,i,j;
	FILE *fp;
	char path[50];
	printf("\nNhap duong dan: ");
	fflush(stdin);
	gets(path);
	fp=fopen(path,"wt");
	if(fp==NULL)
	    printf("\nLoi mo file");
	else
	{
		fprintf(fp,"Cac phan tu cua mang: ");
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			     fprintf(fp,"%3d",a[i][j]);
		}
		fprintf(fp,"\nCac phan tu duong trong mang: ");
		/*Tinh tong cac phan tu duong*/
		int s=0;
		for(i=0;i<m;i++)
		     for(j=0;j<m;j++)
		     {
		     	if(a[i][j]>0)
		     	{
		     		fprintf(fp,"%3d",a[i][j]);
		     		s=s+a[i][j];
		     	}
		     }
		fprintf(fp,"\Tong cac phan tu duong: ");
		fclose(fp);   
	}    
}

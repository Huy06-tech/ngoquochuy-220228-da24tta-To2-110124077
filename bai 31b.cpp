#include<stdio.h>
#define MAX 255
main()
{
	char path1[50], path2[50], ketqua[MAX+1];
	FILE *fp1, *fp2;
	printf("\nNhap duong dan tap tin thu nhat: ");
	fflush(stdin);
	gets(path1);
	printf("\nNhap duong dan tap tin thu hai: ");
	fflush(stdin);
	gets(path2);
	fp1=fopen(path,"at");
	fp2=fopen(path2,"rt");
	if(fp2==NULL||fp1==NULL)
	     printf("\nLoi mo file");
	else
	{
		fprintf(fp1,"\n");
		while(feof(fp2)==0)
		    if(fgets(ketqua,MAX,fp2)!==NULL)
		        fprintf(fp1,"%s",ketqua);
		fclose(fp1);
		fclose(fp2);        
	}    
}

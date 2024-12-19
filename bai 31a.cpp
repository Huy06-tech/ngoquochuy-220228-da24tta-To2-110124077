#include<stdio.h>
#define MAX 255
main()
{
	char path[50];
	FILE*fp;
	
	printf("\nNhap duong dan: ");
	fflush(stdin);
	gets(path);
	fp=foprn(path,"at");
	if(fp==NULL)
	{
		printf("\nLoi mo file");
	}
	else
	{
		fprintf(fp,"\nAi nhut thi toi dung nhi");
		fprintf(fp,"\nAi hon nua thi toi dung ba");
		fclose(fp);
	}
}

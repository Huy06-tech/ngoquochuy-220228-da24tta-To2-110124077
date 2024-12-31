#include"stdio.h"
long int tinhXn(int n);
void main(){
	printf("%d", tinhXn(3));
}
long int tinhFn(int n)
{
	if(n==0)
	      return 1;
	else
	{
		long int s=0;
		for (itn i=0;i<n;i++)
		{
			s=s+(n-1)*(long)(n-1)*tinhXn(n-1);
		}
		return s;
	}
}

double luy_thua(float a,int n)
{
	if(n==0)
	      return 1;
	else
	      return (a*luy_thua(a,n-1));     
}

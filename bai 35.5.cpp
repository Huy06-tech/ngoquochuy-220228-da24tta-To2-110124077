#include"stdio.h"
unsigned int tinhUn(unsigned int n);
void main(){
	printf("%d",tinhUn(6));
}
unsigned int tinhUn(unsigned int n)
{
	if(n<6)
	      return n;
	else{
		unsigned int s=0;
		for (int i=n-1;i>=1;i--){
			s=s+tinhUn(n-1);
		}
		return s;
	}
}

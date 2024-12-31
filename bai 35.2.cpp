#include"stdio.h"
unsigned int UCLN(unsigned int a,unsigned int b);
void main (){
	printf("%d",UCLN(12,8));
}
unsigned int UCLN(unsigned int a,unsigned int b){
	if (a>b)
	      return UCLN(a-b,b);
	else if(b>a)
	      return UCLN(b-a,a);
    else
	      return a;		        
}

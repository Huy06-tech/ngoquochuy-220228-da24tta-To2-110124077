#include"stdio.h"
unsigned int tinhFn(unsigned int n);
void main(){
	printf("%d",tinhFN(5));
}
unsigned int tinhFn(unsigned int n){
	if(n==0||n==1)
	      return 1;
	else{
		return (tinhFn(n-1)+tinhFn(n-2));
	}
}

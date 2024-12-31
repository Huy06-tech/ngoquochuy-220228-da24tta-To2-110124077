#include"stdio.h"
long int tinhUn(unsigned int n);
long int tinhGn(unsigned int n);
void main(){
	printf("%ld", tinhGn(4));
}
long int tinhUn(unsigned int n){
	if(n<5)   return n;
	else 
	     return (tinhUn(n-1)+tinhGn(n-2));
}
long int tinhGn(unsigned int n){
	if(n<8)
	     return (n-3);
	else {
		return (tinhUn(n-1)+tinhGn(n-2));
	}
}

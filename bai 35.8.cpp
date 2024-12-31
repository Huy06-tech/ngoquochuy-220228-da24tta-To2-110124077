#include"stdio.h"
void MoveDisk(int src, int des);
void Tower(int n,int cot1,int cot2,int cot3);
void main(){
	Tower(3,1,2,3);
}
void MoveDisk(int src,int des){
	printf("\nTu %d Den %d\n", src,des);
}
void Tower(int n,int cot1,int cot2,int cot3){
	if(n>0){
		Tower(n-1, cot1, cot3, cot2);
		MoveDisk(cot1, cot3);
		Tower(n-1, cot2, cot1, cot3);
	}
}

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int pow_ten(int a){
	int ret = 1;
	while(a){
		ret *= 2;
		--a;
	}
	return ret;
}
int main(int argc, char *argv[]) {
	while(1){
		char a[16] = {'.'};
		char b[16] = {'.'};
		scanf("%s",a);
		scanf("%s",b);
		short a_int = 0;
		short b_int = 0;
		for(int i = 0; i < strlen(a); i++){
			if(a[i]=='1'){
				a_int += pow_ten(strlen(a)-i-1);
			}
			else continue;
		}
		for(int i = 0; i < strlen(b); i++){
			if(b[i]=='1'){
				b_int += pow_ten(strlen(b)-i-1);
			}
			else continue;
		}
		printf("%d ",a_int);
		printf("%d\n",b_int);
		short n = 0x4000;
		char c;
		scanf("%s",&c);
		if(c=='+') {
			while(n!=0x0000){
				printf("%d",(n&(a_int+b_int))==n);
				n = n>>1;
			}
			printf("\n");
		}
		if(c=='-') {
			//if((a_int-b_int)<0) {
			//	printf("-");
			//}
			while(n!=0x0000){
				if((a_int-b_int)<0){
					short ret = 65535;
					printf("%d",(n&(ret-b_int+a_int+1))==n);
				}
				else {
					printf("%d",(n&(a_int-b_int))==n);
				}
				n = n>>1;
			}
			printf("\n");
		}
		if(c=='*') {
			while(n!=0x0000){
				printf("%d",(n&(a_int*b_int))==n);
				n = n>>1;
			}
			printf("\n");
		}
		if(c=='/') {
			while(n!=0x0000){
				printf("%d",(n&(a_int/b_int))==n);
				n = n>>1;
			}
			printf("\n");
		}
		
			
		
	}
}
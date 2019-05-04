#include <stdio.h>
#include <stdlib.h>
int istrue(int x){
	if(x>=0&&x<=255){
		return 1;
	}
	else return 0;
}



int main(int argc, char *argv[]) {
	int a=0,b=0,c=0,d=0;
	while(scanf("%d.%d.%d.%d",&a,&b,&c,&d)!=EOF){
		if(istrue(a)&&istrue(b)&&istrue(c)&&istrue(d)){
				printf("Yes!\n");
			}
		else printf("No!\n");
	}
	return 0;
}
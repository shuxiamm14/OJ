#include <stdio.h>
#include <math.h>
int isprime(int x){
	int sum = 0;
	for(int i = 1; i <= x;i++){
		if(x%i == 0) sum ++; 
	}
	if(sum == 2) return 1;
	else return 0;
}




int main(int argc, char *argv[]) {
	int n = 1000;
	int i = 0;
	while(n<10000){
		if(isprime(n/1000)&&isprime(n/100)&&isprime(n/10)&&isprime(n/1)){
			printf("%d ",n);
			n++;
			i++;
			if(i==5){
				i=0;
				printf("\n");
			}
		}
		else n++;	
	}	
}
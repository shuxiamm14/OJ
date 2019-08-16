#include <stdio.h>
int isprime(int x){
	int sum = 0;
	for(int i = 1; i <= x;i++){
		if(x%i == 0) sum ++; 
	}
	if(sum == 2) return 1;
	else return 0;
}
int main(int argc, char *argv[]) {
	
	int m = 0;
	while(scanf("%d",&m)!=EOF){
		if(m<5||m>1000) return 0;
		else {
			for(int i = m; i >= 1;){
				if(isprime(i)&&isprime(i+2)){
					printf("%d,%d\n",i,i + 2);
					break;
					i--;
				}
				else{
					i--;
				}
				
				
				
			}
	
		}
	
	}	
}
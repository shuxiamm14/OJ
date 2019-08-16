#include <stdio.h>
#include <math.h>
int a = 1;
int b[1000][1000] = {0};
void new_m(int lr,int lc, int rr, int rc){
	int i = lr;
	int j = lc;
	if(i == rr && j == rc){
		b[i][j] = a;
	}
	while(j!=rc){
		b[i][j++] = a++;
	}
	while(i!=rr){
		b[i++][j] = a++;
	}
	while(j!=lc){
		b[i][j--] = a++;
	}
	while(i!=lr){
		b[i--][j] = a++;
	}
}


int main(int argc, char *argv[]) {
	int n = 0;
	while(scanf("%d",&n)!=EOF){
		//int n_pow = pow(n,2);
		//printf("%d\n",n_pow);
		for(int i = 0,j = n-1; i <= j; i++,j--){
			new_m(i, i, j, j);

		}
		
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j++){
				printf("%-4d ",b[i][j]);
			}
			printf("\n");
		}
		a = 1;
	
		
	}
}
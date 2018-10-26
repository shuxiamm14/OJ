#include<stdio.h>
long long ans[10000];
int main(){
	int n, sum, half;
	scanf("%d", &n);
	sum = n*(n+1)/2;
	if(sum%2){
		printf("0");
	} else {
		half = sum/2;
		ans[0] = 1;
		for(int i=1; i<=half; i++){
			ans[i] = 0;
		}
		for(int i=1; i<=n; i++){
			for(int j=half; j>=i; j--){
				ans[j] += ans[j-i];
			}
		}
		printf("%lld", ans[half]/2);
	}
}

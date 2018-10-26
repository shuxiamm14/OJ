/*
1091 A+B for Input-Output Practice (III)
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K  
VC
*/
#include <stdio.h>
#define MAX 1000
int main()
{
	int num1,num2,ans[MAX],n=0,ca;
	while(scanf("%d %d",&num1,&num2)==2)
	{
		if(num1==0 && num2==0)
			for(ca=0;ca<n;ca++)
				printf("%d\n",ans[ca]);
		else
			ans[n++]=num1+num2;
	}
	
	return 0;
}

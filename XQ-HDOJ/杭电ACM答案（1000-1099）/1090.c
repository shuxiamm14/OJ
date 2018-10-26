/*
1090 A+B for Input-Output Practice (II)
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K  
VC
*/
#include <stdio.h>
#define MAX 1000
int main()
{
	int n,ca,num1,num2,ans[MAX];
	while(scanf("%d",&n)==1)
	{
		for(ca=0;ca<n;ca++)
		{
			if(scanf("%d %d",&num1,&num2)==2)
				ans[ca]=num1+num2;
		}
		for(ca=0;ca<n;ca++)
			printf("%d\n",ans[ca]);
	}
	
	return 0;
}

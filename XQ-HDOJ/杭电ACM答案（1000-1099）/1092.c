/*
1092 A+B for Input-Output Practice (IV)
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K  
VC
*/
#include <stdio.h>
#define MAX 1000
int main()
{
	int num,ans[MAX]={0},n=0,ca;
	while(scanf("%d",&ca)==1)
	{
		if(ca!=0)
			for(;ca>0;ca--)	
			{
				scanf("%d",&num);
				ans[n]+=num;
			}
		else
		{
			for(ca=0;ca<n;ca++)
				printf("%d\n",ans[ca]);
		}
		n++;
	}
	
	return 0;
}

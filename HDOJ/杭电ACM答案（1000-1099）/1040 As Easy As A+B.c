/*
1040 As Easy As A+B
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K  
VC
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define NMAX 1000

//void qsort(void *base, size_t nelem, size_t width, int (*fcmp)(const void *, const void *)

int fintcmp(int * p1,int * p2)
{
	if(*p1>*p2)
		return 1;
	if(*p1==*p2)
		return 0;
	return -1;
}

int main()
{
	int t,ca,cb,n;
	int * pnum[MAX]={0},tn[MAX]={0},* pnow;
	if(scanf("%d",&t)==1)
	{
		for(ca=0;ca<t;ca++)
		{
			if(scanf("%d",&n)==1)
			{
				pnum[ca]=(int *)malloc(sizeof(int)*n);
				pnow=pnum[ca];
				tn[ca]=n;
				for(cb=0;cb<n;cb++)
				{	scanf("%d",pnow);pnow++;}
				qsort(pnum[ca],n,sizeof(int),fintcmp);
			}//if
		}
		for(ca=0;ca<t;ca++)
		{
			n=tn[ca];
			for(cb=0;cb<n;cb++)
			{	
				printf("%d",pnum[ca][cb]);
				if(cb!=n-1)
					printf(" ");
			}
			printf("\n");
		}
		
	}
	return 0;
}

/*
1020 Encoding
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K  
VC
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRINGMAX 10000
#define NMAX 100

int main()
{
	int n,ca,cb,num,len;
	char input[STRINGMAX+1]={0},ans[NMAX][STRINGMAX+1]={0};
	char prechar,*pnow;
	if(scanf("%d",&n)==1)
	{
		for(ca=0;ca<n;ca++)
		{
			scanf("%s",input);
			strupr(input);
			len=strlen(input);
			prechar=input[0];
			pnow=ans[ca];
			num=1;
			for(cb=1;cb<len;cb++)
			{
				if(prechar==input[cb])
				{	num++;}
				else
				{
					if(num==1)
					{	*pnow=prechar;pnow++;}
					else
					{
						itoa(num,pnow,10);
						pnow=ans[ca]+strlen(ans[ca]);
						*pnow=prechar;
						pnow++;
					}
					num=1;
					prechar=input[cb];
				}
			}
			if(num==1)
			{	*pnow=prechar;}
			else
			{
				itoa(num,pnow,10);
				pnow=ans[ca]+strlen(ans[ca]);
				*pnow=prechar;
			}
		}

		for(ca=0;ca<n;ca++)
			printf("%s\n",ans[ca]);
	}
	return 0;
}

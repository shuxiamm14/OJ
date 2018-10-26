/*
1005 Number Sequence
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K
VC
*/
//此题难度在于大规模时的运算时间
//当a的值和b的值够大时会造成数据溢出
//使用数学归纳法可以总结出规律
//对大规模数据的题目得考虑是否有规律
#include <stdio.h>
#include <string.h>

#define BMAX 1000
#define NMAX 100000000
#define MAX 1000

int main()
{
	int a,b,n,flag,end,f,ca,ans;
	short line[MAX]={0};
	while(scanf("%d %d %d",&a,&b,&n)==3)
	{
		if(a==0 && b==0 && n==0)	break;
		if(a<1 || b>BMAX || n>NMAX)	continue;
		a%=7;b%=7;
		if(a==0 && b==0)
			flag=3;
		else
		{
			if(a==0)	flag=1;
			else
				if(b==0)	flag=2;
				else	flag=4;
		}

		if(flag==3)
		{
			if(n<=2)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}

		f=1;line[1]=1;line[2]=1;end=0;
		for(ca=3;ca<=n;ca++)
		{
			if(end==1)	break;
			f=(a*line[ca-1]+b*line[ca-2])%7;
			//printf("%d",f);
			switch(flag)
			{
			case 1:
				if(f==1)
				{	line[0]=line[ca-1];ans=line[n%(ca-1)];end=1;break;}
				else
				{	line[ca]=f;line[ca+1]=f;ca++;break;}
			case 2:
				if(f==1)
				{	line[0]=line[ca-2];line[1]=line[ca-1];ans=line[n%(ca-2)];end=1;break;}
				else
				{	line[ca]=f;break;}
			case 4:
				if(f==1)
				{	
					if(line[ca-1]==1)
					{	line[0]=line[ca-2];ans=line[n%(ca-2)];end=1;break;}
					else
						line[ca]=f;
				}
				else
					line[ca]=f;
			}//switch
		}//for	
		if(end==0)//当f值不是从重复值中得出时，现在f为何值就是答案
			printf("%d\n",f);
        else
            printf("%d\n",ans);
	}

	return 0;
}

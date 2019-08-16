/*
1005 Number Sequence
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K
VC
*/
//�����Ѷ����ڴ��ģʱ������ʱ��
//��a��ֵ��b��ֵ����ʱ������������
//ʹ����ѧ���ɷ������ܽ������
//�Դ��ģ���ݵ���Ŀ�ÿ����Ƿ��й���
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
		if(end==0)//��fֵ���Ǵ��ظ�ֵ�еó�ʱ������fΪ��ֵ���Ǵ�
			printf("%d\n",f);
        else
            printf("%d\n",ans);
	}

	return 0;
}

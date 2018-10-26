/*
1002 A + B Problem II
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K 
VC
*/
//�Ѷ����ڽ����������ķ�����ʵ�ʲ�����
#include <stdio.h>
#include <stdlib.h>
#define DIV 4
#define NUMLONG 1000
#define TMAX 20

short deadd[TMAX]={0};
short flag=0;

int ChangetoNum(char * pstr,short * pnum,short now)
{
	short ca=0,cb=3;
	char divstr[DIV+1];
	divstr[DIV]='\0';
	if(*pstr=='-')
	{
		deadd[now]++;
		pstr++;
	}
	while(pstr[ca]!='\0')	ca++;
	pnum[0]=ca-ca%DIV;
	if(pnum[0]==0)//�ж��Ƿ���һ�����浥Ԫ
		pnum[0]=1;
	else if(pnum[0]==ca)//�ж��Ƿ�û������ı��浥Ԫ
			pnum[0]=(ca-ca%DIV)/DIV;
		else
			pnum[0]=(ca-ca%DIV)/DIV+1;
	//pnum[0]�������ֵı��泤��
	pnum++;;
	while((ca--)>=0)
	{
		if(cb<0)
		{
			*pnum=(short)atoi(divstr);//�ֶ��ַ���ת��Ϊ����
			pnum++;
			cb=3;
			divstr[cb--]=pstr[ca];
		}
		else if(ca<0 && cb<3)//�޷��ϳ�һ���ε��ַ���ת��
			{
				while(cb>=0)
					divstr[cb--]='0';
				*pnum=(short)atoi(divstr);
			}
			else
				divstr[cb--]=pstr[ca];
	}
	return 0;
}

int Calculate(short *pnum1,short *pnum2,short *pans)
{
	short ca,n,temp;
	if(pnum1[0]<pnum2[0])
		n=pnum2[0];
	else
		n=pnum1[0];
	for(ca=1;ca<=n;ca++)
	{
		temp=pnum1[ca]+pnum2[ca]+pans[ca];
		if(temp>=10000)//��������н�λ
		{
			pans[ca]=temp-10000;
			pans[ca+1]=1;
			pans[0]=ca+1;
		}
		else
			pans[ca]=temp;
	}
	pans[0]=pans[0]<=n?n:pans[0];
	return 0;
}

int Calculate2(short *pnum1,short *pnum2,short *pans)//pnum1Ϊ����
{
	short ca,n,temp;
	n=pnum1[0];
	pans[0]=n;
	for(ca=1;ca<=n;ca++)
	{
		temp=pnum1[ca]-pnum2[ca]-pans[ca];
		if(temp==0 && ca==n)
			pans[0]=n-1;
		if(temp<0)//�������Ҫ��λ
		{
			if(pnum1[ca+1]>0)
			{
				pans[ca]=temp+10000;
				pans[ca+1]=1;
			}
		}
		else
			pans[ca]=temp;
	}
	return 0;
}

int PrintAns(char *pleft,char *pright,short *pans,short ca)
{
	short cb,temp;
	printf("Case %d:\n",ca);
	printf("%s + %s = ",pleft,pright);
	if(flag==1)	//�׵�Ԫ������⻯
		printf("%d",-pans[pans[0]]);
	else
		printf("%d",pans[pans[0]]);
	for(ca=pans[0]-1;ca>=1;ca--)
	{
		if(pans[ca]>=1000)//4λȫ��
			printf("%d",pans[ca]);
		else
		{
			//if(ca<pans[0])//�ж��Ƿ�Ϊ��һ����Ԫ
			{
				temp=pans[ca];
				for(cb=0;temp>0;cb++)//��������м��0
					temp/=10;
				for(;cb<4;cb++)
					printf("0");
			}
			if(pans[ca]!=0)	printf("%d",pans[ca]);//���˵�ԪΪ0ʱ��0�Ѿ������ϣ��Ͳ����������
		}
	}
	printf("\n");
	return 0;
}

short WhoBig(short *pnum1,short *pnum2)
{
	short ca;
	if(pnum1[0]>pnum2[0])
		return 1;
	else
		if(pnum1[0]<pnum2[0])
			return -1;
	for(ca=pnum1[0];ca>=1;ca--)
	{
		if(pnum1[ca]==pnum2[ca])
			continue;
		if(pnum1[ca]>pnum2[ca])
			return 1;
		else
			return -1;
	}
	return 0;
}


int main()
{
	short n,ca,big;
	char strleft[TMAX][NUMLONG+1],strright[TMAX][NUMLONG+1];
	short numleft[TMAX][NUMLONG/DIV]={0},numright[TMAX][NUMLONG/DIV]={0};
	short ans[TMAX][NUMLONG/DIV]={0};
	scanf("%d",&n);
	
		ca=0;
		while(ca<n && scanf("%s %s",strleft[ca],strright[ca])==2)
		{
			ChangetoNum(strleft[ca],numleft[ca],ca);//����Ϊ3������Ϊ4������Ϊ1������Ϊ2
			if(deadd[ca]==0)
				deadd[ca]=3;
			ChangetoNum(strright[ca],numright[ca],ca);
			ca++;
		}//while��������
		for(ca=0;ca<n;ca++)
		{
			switch(deadd[ca])
			{
			case 3:
				Calculate(numleft[ca],numright[ca],ans[ca]);
				flag=0;
				break;
			case 2:
				Calculate(numleft[ca],numright[ca],ans[ca]);
				flag=1;
				break;
			case 4:
			case 1:
				big=WhoBig(numleft[ca],numright[ca]);
				if(big==0)
				{
					printf("Case %d:\n",ca+1);
					printf("%s + %s = 0\n",strleft[ca],strright[ca]);
					continue;
				}
				else
					if(big==1)//��ߵ��������ұߵ���
					{
						Calculate2(numleft[ca],numright[ca],ans[ca]);
						if(deadd[ca]==4)//����
							flag=0;
						else 
							if(deadd[ca]==1)//����
									flag=1;
					}
					else 
						if(big==-1)//�ұߵ���������ߵ���
						{
							Calculate2(numright[ca],numleft[ca],ans[ca]);
							if(deadd[ca]==4)//����
								flag=1;
							else 
								if(deadd[ca]==1)//����
									flag=0;
						}
				break;
			}
			PrintAns(strleft[ca],strright[ca],ans[ca],ca+1);
			if(ca!=n-1)	
				printf("\n");
		}//for��������
	
	return 0;
}
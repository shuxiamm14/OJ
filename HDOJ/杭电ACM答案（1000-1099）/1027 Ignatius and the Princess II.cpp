/*
1027 Ignatius and the Princess II
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

78 MS 352 KB 1876 B 
GUN C++
*/
#include <iostream.h>
#include <string.h>
using namespace std;

const int NMAX=1000;
const int MMAX=10000;
int changenum[NMAX]={0};
int fa,fb,a,b;


int Shiftnum(int x,int y,int step)
{
    int temp,ca;
    if(x>=0 && y>=1)
    {
        temp=changenum[step];
		if(x!=0)//x��0ʱ��˵����λ���øı䣬����ı���ٶԺ������������
		{
			changenum[step]=changenum[step+x];
			for(ca=step+x;ca>step;ca--)
			{   changenum[ca]=changenum[ca-1];}
			changenum[step+1]=temp;
		}
		fa/=a;fb/=b;a--;b--;temp=y;
		if(b<=1)//��b��1ʱ��˵�����������һλ�ı仯����ֻ��һ����Χ��û���¸���Χ
		{	x=temp;y=-1;}
		else
		{	y=temp%fa;x=(temp-y)/fa;}
		if(y==0)//y���ڣ�1,a!��
		{	y=fa;x--;}//��y��0ʱ��˵�����˷�Χ�����ֵ����û�е��¸���Χ����x--
		
        Shiftnum(x,y,step+1);
    }

    return 1;
}

int main()
{
    int ca,now,x,y,n,m,temp;
    while(cin>>n>>m)
    {
		if(n==1)
		{	cout<<1<<endl;continue;}
        ca=temp=1;
		if(m==1)
		{
			for(ca=1;ca<=n;ca++)
			{
				cout<<ca;
				if(ca<n)
					cout<<" ";
				else
					cout<<endl;
			}
			continue;
		}
        while(m>temp)
        {   temp*=ca;ca++;}
        b=ca-1;a=b-1;fb=temp;fa=temp/b;
        for(ca=1;ca<=n-b;ca++)
        {   cout<<ca<<" ";}
        for(ca=n-a,now=0;ca<=n;ca++,now++)
        {   changenum[now]=ca;}

        y=m%fa;x=(m-y)/fa;now=a;//ÿ����Χ�Ĵ�СΪa!,xΪ�˷�Χ���±꣬y���¸���Χ���±�
		if(y==0)
		{	y=fa;x--;}
		
        Shiftnum(x,y,0);
        for(ca=0;ca<=now;ca++)
        {
            cout<<changenum[ca];
            if(ca<now)
            {   cout<<" ";}
            else
            {   cout<<endl;}
        }
        memset(changenum, 0, sizeof(changenum));
    }
    return 0;
}


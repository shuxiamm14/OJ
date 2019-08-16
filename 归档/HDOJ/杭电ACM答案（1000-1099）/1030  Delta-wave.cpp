/*
1030 Delta-wave
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 256 K

GUN C++
*/
#include <iostream>
#include <cmath>
using namespace std;

const long int MAX=1000000000;

int toPos(const long int num,long int & x,long int & y,long int & flag)
{
    float fx;
    fx=sqrt(num);
    x=(long int)fx;
    if(fx!=x)
        x++;
    y=num-(x-1)*(x-1);
    if(y%2==1)//������Ϊ0��������1
        flag=0;
    else
        flag=1;
    return 1;
}

int main()
{
    long int n,m,temp,way,step,y12,y22;
    long int x1,y1,x2,y2,flag1,flag2;
    while(cin>>n>>m)
    {
        if(n>m)
        {   temp=m;m=n;n=temp;}
        toPos(n,x1,y1,flag1);
        toPos(m,x2,y2,flag2);
        
        if(x1==x2)
        {   way=abs(y2-y1);}
        else
        {
            way=2*(x2-x1)+flag1-flag2; //�ȼ������������ǵľ��룬����ǵ������ھ�����Ӽ�1
            y12=y1-flag1;              //��������ת����Ϊ��ʱ��
            y22=y12+2*(x2-x1);
            if(y2<y12)//y12----y22
            {   way+=y12-y2+flag2;}
            if(y2>y22)
            {
                way+=y2-y22+flag2;
                if(flag1==1)
                {   way-=2;}//����ʼΪ�����ǣ��յ���������Ƿ�Χ��
            }               //��Ϊһ��Ϊ��ʱ��ת���������·��-2
        }
        cout<<way<<endl;
    }
    return 0;
}


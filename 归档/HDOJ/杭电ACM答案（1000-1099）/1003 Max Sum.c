/*
1003 Max Sum
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K
GUN C

input 4 -6 -8 0 -3
output 0 1 1
OJ有错误，连不正确的也AC
*/
#include <stdio.h>

int input[100000];

int main()
{
   int i,j;
   int start,end;
   int x,y;
   int b;
   int n;
   int max;
   int cs,k;
   int flag;
   scanf("%d",&cs);
   for(k=1;k<=cs;k++)
   {
       printf("Case %d:\n",k);
       scanf("%d",&n);
       for(i=0;i<n;i++)
       scanf("%d",&input[i]);
       x=0;y=0;
       start=0;end=0;
       max=-10000000;
       b=0;
       flag=0;
       for(i=0;i<n;i++)
       {
           if(input[i]>=0)
           {
               if(flag==0)
               {
                   max=0;
                   x=i;
               }
               flag=1;
           }
           if(flag==1)
           {
               if(b+input[i]<0)
               {
                   b=0;
                   x=i+1;
               }
               else
               {
                   b=b+input[i];
                   y=i;
               }
               if(max<b)
               {
                   max=b;
                   start=x+1;
                   end=y+1;
               }
           }
           else
           {
               if(max<input[i])
               {
                   max=input[i];
                   start=i+1;
                   end=i+1;
               }
           }
       }
       printf("%d %d %d\n",max,start,end);
       if(k!=cs) printf("\n");
   }
return 0;
}



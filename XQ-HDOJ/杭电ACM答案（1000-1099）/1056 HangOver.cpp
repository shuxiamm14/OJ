/*
1056 HangOver
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C
*/
#include<stdio.h>

int main( )
{
   double len,t;
   int i;

   scanf("%lf",&len);
   while(len!=0)
   {
       i=2;
       t=0;
       while(t<len)
       {
           t+=1.0/i;
           i++;
       }
       printf("%d card(s)\n",i-2);
       scanf("%lf",&len);
   }
   return 0;
}



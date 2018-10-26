/*
1098 Ignatius's puzzle
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
//f(x)=5*x^13+13x^5+k*ax
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k,i,x,j,a,b,c;
   
    while(scanf("%d",&k)!=EOF)
    {
        for(i=1;i<1000;i++)
            if( (18+k*i)%65==0 )
            {   printf("%d\n",i);break;}
        if(i==1000)
            printf("no\n");
    }
    return 0;
}



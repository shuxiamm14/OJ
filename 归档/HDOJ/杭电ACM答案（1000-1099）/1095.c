#include<stdio.h>
#define MAX 1000

int main()
{
    int n=0,ca,a,b,ans[MAX]={0};
    while(scanf("%d %d",&a,&b)==2)
    {
        ans[n]=a+b;
        n++;
    }
    for(ca=0;ca<n;ca++)
    {
        printf("%d\n\n",ans[ca]);
    }
    return 0;
}

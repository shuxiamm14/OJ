#include<stdio.h>
#define MAX 1000

int main()
{
    int n,ca=0,cb,num,ans[MAX]={0};
    while(scanf("%d",&n)==1)
    {
                for(cb=0;cb<n;cb++)
                {
                    scanf("%d",&num);
                    ans[ca]+=num;
                }
                ca++;

    }
    for(cb=0;cb<ca;cb++)
    {
        printf("%d\n",ans[cb]);
    }
    return 0;
}

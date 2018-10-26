#include<stdio.h>
#define MAX 1000

int main()
{
    int n,m,ca,cb,num,ans[MAX]={0};
    if(scanf("%d",&n)==1)
    {
        for(ca=0;ca<n;ca++)
        {
            if(scanf("%d",&m)==1)
            {
                for(cb=0;cb<m;cb++)
                {
                    scanf("%d",&num);
                    ans[ca]+=num;
                }
            }
        }
        for(ca=0;ca<n;ca++)
        {
            printf("%d",ans[ca]);
            printf("\n");
        }
    }
    return 0;
}

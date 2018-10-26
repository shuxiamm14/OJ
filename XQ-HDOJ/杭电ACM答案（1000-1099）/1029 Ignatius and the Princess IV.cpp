/*
1029 Ignatius and the Princess IV
Time Limit : 1000 ms  Memory Limit : 1024 K  Output Limit : 1024 K

375 MS 332 KB 748 B 
GUN C++
*/
#include <iostream.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const int NMAX=999999;

int main()
{
    int n,times,now,ca;
    int num[10000]={0};
    while(scanf("%d",&n)==1)
    {
        if(n%2==0)
            break;
        times=(n+1)/2;
        for(ca=0;ca<n;ca++)
        {
            scanf("%d",&now);
            num[now]++;
            if(num[now]>=times)
            {
                printf("%d\n",now);
				ca++;
                break;
            }
        }
		for(;ca<n;ca++)
		{	scanf("%*d");}
        memset(num, 0, sizeof(num));
    }
    return 0;
}



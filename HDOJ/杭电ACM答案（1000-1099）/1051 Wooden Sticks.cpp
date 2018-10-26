/*
1051 Wooden Sticks
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/

#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

struct Wood
{
    int l,w;
    bool operator<(const Wood & temp) const
    {
        if(l<temp.l)
            return true;
        else
            if(l==temp.l)
                if(w<temp.w)
                    return true;
        return false;
    }
};
Wood input[5000];
int machine[5000],temp;

int main()
{
    int t,n,i,j,pos,min;
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        min=0;
        for(i=1;i<=n;i++)
            scanf("%d %d",&input[i].l,&input[i].w);
        sort(input+1,input+n+1);
        memset(machine,0,sizeof(machine));
        
        min=1;machine[1]=input[1].w;
        for(i=2;i<=n;i++)
        {
            temp=-1;
            for(j=1;j<=min;j++)
                if( input[i].w>=machine[j] && temp < machine[j])
                {   temp=machine[j];pos=j;}

            if(temp<0)
            {   machine[++min]=input[i].w;}
            else
            {   machine[pos]=input[i].w;}
        }
        
        printf("%d\n",min);
    }
    return 0;
}


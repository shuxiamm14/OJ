#include <cstdio>
#include <memory>
using namespace std;
const int Max=10000;
int k,sum,idiv;
int dia[7];
bool cn[2][Max],*pre,*next,*t;

int main()
{
    int i,j,n;
    bool flag;
    
    k=1;
    while(scanf("%d %d %d %d %d %d",&dia[1],&dia[2],&dia[3],&dia[4],&dia[5],&dia[6])!=EOF)
    {
        for(i=1,sum=0;i<=6;i++)    
        {
            if(dia[i]%2==1 && dia[i]>61)
                dia[i]=61;
            else if(dia[i]%2==0 && dia[i]>60)
                dia[i]=60;
            sum+=dia[i]*i;
        }
        if(sum==0)
            break;
        else if(sum%2==1)
            flag=false;
        else
        {
            memset(cn,0,sizeof(cn));
            for(i=0;i<=dia[1];i++)
                cn[0][i]=true;
                
            pre=cn[0];next=cn[1];
            idiv=sum/2;
            for(i=2;i<=6;i++)
            {
                if(dia[i]>0)
                {
                    for(j=0;j<Max && j<=idiv;j++)
                    {
                        if(pre[j])
                            for(n=1;n<=dia[i];n++)
                                next[j+n*i]=true;
                    }
					memcpy(pre,next,Max);
                }
            }
            flag=pre[idiv];
        }
        printf("Collection #%d:\n",k);
        if(flag)
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
        k++;
    }
    return 0;
}


//数据过大，改进dp，查找用二分
//O( n*log n ) 
#include <cstdio>
using namespace std;
const int Max=500001;
struct infor
{
	int r;
}road[Max];
int dp[Max];

/*********二分查找********************/
inline int divFind(int num[],int findnum,int size)
{
    int low=1,high=size,mid;
    while(high>=low)
    {
        mid=(low+high)/2;
        if(num[mid]==findnum)
            return mid-1;
        else
        {
            if(num[mid]>findnum)
            {   
            	high=mid-1;
            	if(num[high] < findnum)
            		return high;
			}
            else
            {   
            	low=mid+1;
            	if(num[low] > findnum)
            		return low-1;
			}
        }
    }
}

int main()
{
	int i,j,n,p,r,t;
	int rmax,pos;
	t=1;
	while( scanf("%d",&n)!=EOF )
	{
		printf("Case %d:\n",t);
		for(i=0;i<n;i++)
			scanf("%d",&p), scanf("%d",&road[p].r) , dp[i]=0;
	
		rmax=1;
		dp[1]=road[1].r;
		for(i=2;i<=n;i++)
		{
			if(road[i].r > dp[rmax])
			{
				dp[++rmax]= road[i].r;
			}
			else
			{
				pos=divFind(dp,road[i].r,rmax);
				if(dp[pos+1] > road[i].r)
					dp[pos+1]=road[i].r;
			}//if
		}//for
		if(rmax > 1) 
			printf("My king, at most %d roads can be built.\n\n",rmax); 
		else 
			printf("My king, at most %d road can be built.\n\n",rmax); 
		t++;
	}
	return 0;
}

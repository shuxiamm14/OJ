//贪心 
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int t[1100],k[1100];

int main()
{
	int i,j,i2,j2;
	
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);
		for(i=0;i<n;i++)
			scanf("%d",&k[i]);
		sort(t,t+n);
		sort(k,k+n);
		m=0;
		i=0;j=n-1;i2=0;j2=n-1;
		for(;j2>=0 && j>=0 && j>=i;j--,j2--)
		{
			if(k[j2]>t[j])//皇帝好马 > 田忌好马 , 田忌输 , 用劣马 
			{
				m-=200;
				i++;j++;
			}
			else if(k[j2]<t[j])//皇帝好马 < 田忌好马 , 田忌赢 , 用好马 
			{
				m+=200;
			}
			else//相同的好马 
			{
					while(k[i2]<t[i] && i<j)//皇帝劣马 < 田忌劣马 , 田忌赢 
					{
						m+=200;
						i++;i2++;
					}
					if(i!=j)//皇帝劣马 >= 田忌劣马
					{
						if(k[j2]>t[i])
							m-=200;
						i++;j++;
					}
			}

		}
		printf("%d\n",m);
	}
	return 0;
}

#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
char code[30],pass[30];
int len;

bool dfs(int n,int deep)
{
	int i,t,nt;
	char ct;
	
	if(n==0 && deep==6) //×¢Òâ±ß½ç 
		return true;
	else if(deep>5)
		return false;
	for(i=len-1;i>=0;i--)
	{
		if(code[i]>0)
		{
			ct=code[i];
			nt=ct-'A'+1;
			code[i]=0;
			switch(deep)
			{
			case 1:
				t=nt;
				break;
			case 2:
				t=-nt*nt;
				break;
			case 3:
				t=nt*nt*nt;
				break;
			case 4:
				t=-nt*nt*nt*nt;
				break;
			case 5:
				t=nt*nt*nt*nt*nt;
				break;
			}
			if( dfs(n-t,deep+1) )
			{
				pass[deep-1]=ct;
				return true;
			}
			code[i]=ct;
		}
	}//for
}

int main()
{
	int i,j,n;

	while( scanf("%d %s",&n,code)!=EOF && n!=0)
	{
		len=strlen(code);
		sort(code,code+len);
		if( dfs(n,1) )
			printf("%s",pass);
		else
			printf("no solution");
		printf("\n");
	}
	return 0;
}

/*
1066 Last non-zero Digit in N!
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include<cstdio> 
#include<cstring> 
using namespace std; 

const int MAX=10010; 

int lastdigit(char *s) 
{ 
	const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2}; 
	int len=strlen(s),a[MAX],i,c,ret=1; 
	
	if(len==1) 
		return mod[s[0]-'0']; 
	for(i=0;i<len;i++) 
		a[i]=s[len-1-i]-'0'; 
	for( ; len ; len-=!a[len-1]) 
	{
		ret=ret*mod[a[1]%2*10+a[0]]%5; 
		for (c=0,i=len-1 ; i>=0 ; i--) 
			c=c*10+a[i],a[i]=c/5,c%=5; 
	} 
	return ret+ret%2*5; 
} 

int main() 
{ 
	char s[1001]; 
	while(scanf("%s",s)!=EOF) 
		printf("%d\n",lastdigit(s)); 
	return 0; 
} 

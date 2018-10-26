/*
1075 What Are You Talking About
Time Limit : 5000 ms  Memory Limit : 102400 K  Output Limit : 1024 K

GUN C++
*/

#include <cstdio>
#include <string>
using namespace std;

struct trie
{
	trie * next[26];
	int index;
};
trie *thead;
char dic[1000000][20];

inline trie * newnode()
{
	int i;
	
	trie *t;
	t=(trie*)malloc(sizeof(trie));
	memset(t,0,sizeof(trie));
	return t;
}
void insert(trie * s,char x[],int pos)
{
	int i;
	trie *t;
	
	for(i=0; x[i] ; i++)
	{
		if( s->next[ x[i]-'a' ] )
			s=s->next[ x[i]-'a' ];
		else
		{
			t=newnode();
			s->next[ x[i]-'a' ]=t;
			s=t;
		}
	}//for
	s->index=pos;
}
void deltrie(trie * s)
{
	int i;
	
	for(i=0;i<26;i++)
   	{
		if( s->next[i] ) 
			deltrie(s->next[i]);
	}
	free(s);
	s=NULL;
}
int find(trie *s,char x[])
{
	int i;
	
	if(x[0]==0)
		return -1;
	for(i=0; x[i] ; i++)
	{
		if( s->next[ x[i]-'a' ] )
			s=s->next[ x[i]-'a' ];
		else
			break;	
	}
	if(x[i]==0)
		return s->index;
	else
		return -1;
}


int main()
{
    int t,n,i,j,all;
    char word[20],mars[20],ch;
    
    thead=newnode();
    while(scanf("%s",word)==1)
        if(word[0]=='S')
            break;
    i=1;
    while(scanf("%s",dic[i])==1 && dic[i][0]!='E')
    {
        scanf("%s",mars);
        insert(thead,mars,i);
		i++;
    }
   	all=i;
   	
   	while(scanf("%s",word)==1)
        if(word[0]=='S')
            break;
    getchar();
    j=0;
    while(scanf("%c",&ch)==1 && ch!='E')
    {
        if(ch>='a' && ch<='z')
        {
        	mars[j]=ch;
			j++;   
        }
        else
        {
			mars[j]=0;
			t=find( thead , mars );
			j=0;
			if(t>0)
				printf("%s",dic[t]);
			else if(mars[0]!=0)
				printf("%s",mars);
			printf("%c",ch);
		}
    }//while
    deltrie(thead);
    return 0;
}


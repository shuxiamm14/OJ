#include <stdio.h>
#include <string.h>

#define MAX 1000

char balloon[MAX][15];
int Snum[MAX];


void count(char *str);
int Hash_insert(char *str,int sum);


int main()
{
    int i,max,max_num;
    char color[15];
    int N=0;
    while(scanf("%d",&N)!=EOF){
        if(N==0) break;
        memset(balloon,'\0',sizeof(balloon));
        memset(Snum,'\0',sizeof(Snum));
        for(i=0;i<N;i++){
            scanf("%s",color);
            count(color);
        }
        max=Snum[0];
        for(i=0;i<MAX;i++) {
            if(max<Snum[i]){
                max_num=i;
                max=Snum[i];
            }
        }
    printf("%s\n",balloon[max_num]);
    }
    return 0;
}
void count(char *str)
{
    int len =0;
    int i;
    int sum=0;
    len=strlen(str);
    for(i=0;i<len;i++){
        sum+=str[i];
    }
    sum=sum%MAX;
    sum=Hash_insert(str,sum);
    Snum[sum]++;
}
int Hash_insert(char *str,int sum)
{
    if(balloon[sum][0]){
        if( strcmp(str,balloon[sum]) ){
            sum++;
            Hash_insert(str,sum);
        }
    }
    else{
        strcpy(balloon[sum],str);
    }
   return sum;
}

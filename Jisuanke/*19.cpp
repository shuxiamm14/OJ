#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[99999];
int dp[99999];
int main(){
    int n,i,j;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        dp[0]=0;
        for(i=0;i<n;i++){
            for(j=1;j<=a[i]&&i+j<n;j++){
                if(dp[i+j]<=0){
                    dp[i+j]=dp[i]+1;
                }
                else{
                    if(dp[i]+1<dp[i+j]){
                        dp[i+j]=dp[i]+1;
                    }
                }

            }
        }
        printf("%d\n",dp[n-1]);
    }

    return 0;
}

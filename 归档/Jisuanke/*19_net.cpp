/*
name: jisuanke_T20 - jump game
author: yichin
algorithm: dynamic programing
*/
#include <iostream>
#include <cstdio>
#include <cstring>

#define MaxN 1005

using namespace std;

int dp[MaxN][MaxN];

int main()
{
    int n = 0;
    int A[MaxN] = {0};
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &A[i]);
    }
    //dynamic programing
    //dp[i][j] = k means on location i with the last jump distance j, the times of jump is k
    //dp[i][j] = min(dp[i-j][k]) k=[0,n]

    //initialize array
    int min_times[MaxN];
    memset(min_times, -1, sizeof(min_times));
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    min_times[0] = 0;

    for(int i=1; i<n; ++i){
        for(int j=1; j<=i; ++j){ dp[i][j] = ((min_times[i-j] > -1) && (A[i-j] >= j)) ? min_times[i-j] + 1 : -1;
            if(min_times[i] < 0){ min_times[i] = dp[i][j]; }else if(dp[i][j] > -1 && dp[i][j] < min_times[i]){
                min_times[i] = dp[i][j];
            }
        }
    }
    printf("%d\n", min_times[n-1]);
    return 0;
}

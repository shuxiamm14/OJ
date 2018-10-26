#include<iostream>
using namespace std;

int dp[201][101];
int main(int argc, char const *argv[]) {
  int N;
  int K;
  while(cin >> N >> K){
    for(int i = 1 ; i <= K ; i ++){
      dp[1][i] = 1;
    }
    for(int j = 2 ; j <= K ; j ++){
      for(int i = 2 ; i <= N ; i ++){
        for(int m = 1; m <= i - 1 ; m ++){
          dp[i][j]=(dp[i][j]+dp[m][j-1]*dp[i-1-m][j-1])%9901;//不懂
        }
      }
    }
    cout << (dp[N][K]-dp[N][K-1]+9901)%9901 << endl;//不懂

  }
  return 0;
}

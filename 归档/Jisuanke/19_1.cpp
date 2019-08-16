
#include<iostream>
using namespace std;

int main(){
  int n = 0 ;

  while(cin >> n){
    int a[n];
    int dp[n];
    for(int i = 0 ; i < n ; i ++){
      cin >> a[i];
    }
    dp[n-1] = 0;
    for(int i = n - 2 ; i >= 0 ; i --){
      dp[i] = n;
      for(int j = i ; j < n && j <= i + a[i] ; j ++){
        dp[i] = dp[i] < dp[j] + 1 ? dp[i] : dp[j] + 1;
      }
    }
    cout << dp[0] << endl;
  }
}

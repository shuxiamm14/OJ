#include <iostream>
#include <cstring>
#define N 201
#define MOD 9901
using namespace std;
int dp[N][N], n, k; //
int main() {
    cin>>n>>k;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 3; j <= n; j += 2) {
            for (int p = 1; p <= j - 2; p += 2) {
                dp[j][i] = (dp[j][i] + dp[p][i - 1] * dp[j - p - 1][i - 1])% MOD;
            }
        }
    }
    cout<<(dp[n][k] - dp[n][k - 1] + MOD) % MOD<<endl;
}

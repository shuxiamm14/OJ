/**0-1 knapsack d(i, j)表示前i个物品装到剩余容量为j的背包中的最大重量**/

#include<iostream>
using namespace std;
#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN];
int d[MAXN][MAXC];

int main(){
	int n, c;
	while(cin >> n >> c){
		for(int i=0; i<n; ++i){
      cin >> V[i] >> W[i];
    }
		for(int i=0; i<=n; ++i){
			for(int j=0; j<=c; ++j){
				if(i == 0) d[i][j] = 0;//方便记忆
        if(i >0 && j < V[i-1]) d[i][j] = d[i-1][j];//方便记忆
				if(i >0 && j >= V[i-1]){
          d[i][j]=d[i-1][j-V[i-1]]+W[i-1] > d[i-1][j] ?  d[i-1][j-V[i-1]]+W[i-1]  : d[i-1][j];//方便记忆
        }
			}
		}

		cout << d[n][c] << endl;//最终求解的最大价值
	}
	return 0;
}
//原始核心代码
//什么是动态规划？动态规划的意义是什么？
//https://www.zhihu.com/question/23995189/answer/35429905
//https://www.zhihu.com/question/23995189
//http://www.hawstein.com/posts/dp-knapsack.html
//for(int i=0; i<=n; ++i){
//			for(int j=0; j<=C; ++j){
//			 d[i][j] = i==0 ? 0 : d[i-1][j];
//			 if(i>0 && j>=V[i-1])	d[i][j] >?= d[i-1][j-V[i-1]]+W[i-1];
//		  }
//}

/*
ID: jzzlee1
PROG:nocows
LANG:C++
一棵k层的二叉树，含有n个结点，每个结点可能有0或者2个孩子，求所有可能的二叉树结构数对9901取余的结果。刚开始想到动态规划，但是没想出好的动态转移方程，后来想搜索，复杂度太高。无奈看了结题报告。

        dp[i][j]表示i个结点可以组成的不超过j层的不同二叉树的数量。一共i个结点，除了根结点，还有i-1个结点，左子树m个结点，右子树i-1-m个结点，左子树不超过j-1层的数量dp[m][j-1]，右子树不超过j-1层的数量dp[i-1-m][j-1]，因此dp[i][j]=dp[m][j-1]*dp[i-1-m][j-1]，又因为m的取值为1,2,…,i-2，所以dp[i][j]= dp[1][j-1]*dp[i-2][j-1]+dp[2][j-1]*dp[i-3][j-1]+...+dp[i-2][j-1]*dp[1][j-1]，即dp[i][j]=∑（dp[m][j-1]*dp[i-1-m][j-1]）（m=1,2…,i-2）。
*/
//#include<iostream>
#include<fstream>
using namespace std;
ifstream cin("nocows.in");
ofstream cout("nocows.out");
int dp[210][110];
int main()
{
	int n,k;
	cin>>n>>k;
	int i,j,m;
	for(j=0;j<=k;j++)//设置边界条件
		dp[1][j]=1;
	for(j=2;j<=k;++j)
		for(i=2;i<=n;++i)
			for(m=1;m<=i-1;++m)
				dp[i][j]=(dp[i][j]+dp[m][j-1]*dp[i-1-m][j-1])%9901;//递归求解
	cout<<(dp[n][k]-dp[n][k-1]+9901)%9901<<endl;
	return 0;
}

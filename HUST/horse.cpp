#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int r, c;
int cnt, tot;
int wayr[8] = {2, 2, 1, -1, -2, -2, 1, -1}, wayc[8] = {1, -1, 2, 2, 1, -1, -2, -2}; //进行移动
bool mark[1001][1001];                                                              //判断该数是否被标记过
bool check(int x, int y)                                                            //判断是否出局
{
    if (x >= 0 && y >= 0 && x < r && y < c)
        return true;
    return false;
}
void search(int x, int y) //搜索函数
{
    for (int i = 0; i < 8; i++)
        if (check(x + wayr[i], y + wayc[i]) && !mark[x + wayr[i]][y + wayc[i]]) //判断
        {
            mark[x + wayr[i]][y + wayc[i]] = true;
            tot++;
            if (tot == r * c - 1)
                cnt++;
            search(x + wayr[i], y + wayc[i]); //下一轮回溯
            tot--;
            mark[x + wayr[i]][y + wayc[i]] = false; //回溯
        }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        cnt = 0;
        int m, n;
        scanf("%d%d%d%d", &r, &c, &m, &n);
        if (!check(m, n))
            printf("0\n");
        else if (r == 1 && c == 1)
            printf("1\n");
        else
        {
            mark[m][n] = true; //标记起点
            search(m, n);
            printf("%d\n", cnt);
            memset(mark, 0, sizeof(mark));
        }
    }
}
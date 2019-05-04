#include <stdio.h>
#include <string.h>
#define MAX 21
int state[MAX][MAX], A, B, C; //状态数组state[i][j]代表A试管中有 i 升 溶液
                              // B试管中有 j 升溶液的状态是否存在
void dfs(int a, int b, int c) {
  state[a][b] = 1;
  if (a < A) { //
    if (c >= A - a && state[A][b] == 0)
      dfs(A, b, c - A + a); //可倒满
    if (c < A - a && state[a + c][b] == 0)
      dfs(a + c, b, 0); //从c倒入a，不可倒满，以下也是
    if (b >= A - a && state[A][b - A + a] == 0)
      dfs(A, b - A + a, c);
    if (b < A - a && state[a + b][0] == 0)
      dfs(a + b, 0, c); //从b倒入a
  }
  if (b < B) {
    if (c >= B - b && state[a][B] == 0)
      dfs(a, B, c - B + b);
    if (c < B - b && state[a][b + c] == 0)
      dfs(a, b + c, 0); //从c倒入b
    if (a >= B - b && state[a - B + b][B] == 0)
      dfs(a - B + b, B, c);
    if (a < B - b && state[0][a + b] == 0)
      dfs(0, a + b, c); //从a倒入b
  }
  if (c < C) {
    if (a >= C - c && state[a - C + c][b] == 0)
      dfs(a - C + c, b, C);
    if (a < C - c && state[0][b] == 0)
      dfs(0, b, c + a); //从a倒入c
    if (b >= C - c && state[a][b - C + c] == 0)
      dfs(a, b - C + c, C);
    if (b < C - c && state[a][0] == 0)
      dfs(a, 0, b + c); //从b倒入c
  }
}
int main() {
  int i;
  scanf("%d%d%d", &A, &B, &C);
  memset(state, 0, sizeof(state));
  dfs(0, 0, C);
  int frist = 1; //用于保证输出格式，首次输出不在数字前加空格
  for (i = B; i >= 0; i--) {
    if (state[0][i]) { //若存在A试管为0，B试管为 i的状态，则输出
      if (frist)
        frist = 0;
      else
        printf("");
      printf("%d ", C - i);
    }
  }
  return 0;
}

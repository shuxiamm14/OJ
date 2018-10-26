/*
1074 Doing Homework
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <stdio.h>
#include <memory.h>
 
int news[1 << 15][2], olds[1 << 15][2];
int C[15], D[15], mark[16];
int nl[1 << 15], nl2[1 << 15];
int best[15];
char prev[15][1 << 15];
bool flag[1 << 15];
char course[15][101];
 
inline int cost(int t, int d, int c)
{
     if(t + c <= d) return 0;
     else return t + c - d;
}
 
int main()
{
     int cas, cos, i, j, k, l, v, n, cnt, cnt2;
     for(i = 0; i <= 15; ++i) mark[i] = 1 << i;
     scanf("%d", &cas);
     while(cas--)
     {
         scanf("%d", &cos);
         for(i = 0; i < cos; ++i) 
		 	scanf("%s %d %d", course[i], &D[i], &C[i]);
         memset(news, 0x7F, sizeof(news));
         memset(prev, 0xFF, sizeof(prev));
         cnt2 = 0;
         for(i = 0; i < cos; ++i)
         {
              nl2[cnt2++] = mark[i];
              news[mark[i]][0] = C[i]; // ���һ�����������ʱ��
              news[mark[i]][1] = cost(0, D[i], C[i]); // ��ǰ״̬����
              prev[0][mark[i]] = i;
         }
         for(i = 0; i < cos - 1; ++i)
         {
              cnt = cnt2;
              cnt2 = 0;
              
              memset(flag, false, sizeof(flag));
              memcpy(nl, nl2, sizeof(nl));
              
              memcpy(olds, news, sizeof(olds));
              memset(news, 0x7F, sizeof(news));
              
              for(j = 0; j < cnt; ++j)
              {
                   l = nl[j];
                   for(k = 0; k < cos; ++k)
                   {
                       if(mark[k] & l) continue;
                       n = mark[k] | l;
                       v = cost(olds[l][0], D[k], C[k]) + olds[l][1];
                       if(v < news[n][1])
                       {
                            if(!flag[n])
                            {
                                 nl2[cnt2++] = n;
                                 flag[n] = true;
                            }
                            news[n][1] = v;
                            news[n][0] = olds[l][0] + C[k];
                            prev[i + 1][n] = k;
                       }
                   }
              }
         }
         best[cos-1] = prev[cos-1][mark[cos] - 1];
         i = cos-1; l = mark[cos] - 1;
         while(i > 0)
         {
              l = l & (~mark[best[i]]) & (mark[cos] - 1);
              i--;
              best[i] = prev[i][l];
         }
         printf("%d\n", news[mark[cos] - 1][1]);
         for(i = 0; i < cos; ++i)
              printf("%s\n", course[best[i]]);
     }
     return 0;
}


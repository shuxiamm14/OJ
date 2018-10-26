/*
1084 What Is Your Grade?
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

struct info
{
     int index;
     int p;
     int t;
};

info stu[100];
int v[101], c[6], cc[10], ss[] = {50, 60, 65, 70, 75, 80, 85, 90, 95, 100};

bool cmp(const info& a, const info& b)
{
     if(a.p != b.p) return a.p > b.p;
     else return a.t < b.t;
}

int main()
{
     int n, i, j, k,m,h,s;

     while(scanf("%d",&n)==1 && n>=0)
     {
         memset(c, 0, sizeof(c));
         memset(cc, 0, sizeof(cc));
         for(i = 0; i < n; ++i)
         {
              stu[i].index = i + 1;
              scanf("%d",&stu[i].p);
              scanf("%d:%d:%d",&h,&m,&s);
              stu[i].t=s+60*(m+60*h);
              c[stu[i].p]++;
         }
         sort(stu, stu + n, cmp);
         cc[9] = c[5];
         for(i = 9; i >= 3; i -= 2)
         {
              cc[i-1] = c[i / 2] / 2;
              cc[i-2] = c[i / 2] - cc[i-1];
         }
         k = 0;
         for(i = 9; i >= 1; --i)
         {
              j = cc[i];
              while(j--)
              {
                   v[stu[k].index] = ss[i];
                   k++;
              }
         }
         for(; k <= n; ++k) v[stu[k].index] = 50;
         for(i = 1; i <= n; ++i) cout << v[i] << endl;
         cout << endl;
     }
     return 0;
}


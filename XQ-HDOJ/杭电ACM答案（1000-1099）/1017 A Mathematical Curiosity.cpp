/*
1017 A Mathematical Curiosity
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
/*Input & Sample Input
1（测试数据组的组数）

10 1（每组测试数据中的一个，分别代表n,m）
20 3
30 4
0 0（每组测试数据由m=0,n=0结束)

Output & Sample Output

Case 1: 2（输出对数）
Case 2: 4
Case 3: 5

(测试数据组与组间有一空行)*/

#include<iostream>
using namespace std;

int main()
{
  int a,b,i,j,count=0;
  int c,n,m,v;
  float d;
  cin>>c;
  for(i=0;i<c;i++)
  {
      for(j=1;;j++)
      {
          cin>>n>>m;
          if(n==0&&m==0)
              break;
          for(b=1;b<n;b++)
              for(a=1;a<b;a++)
              {
                  v=(int)(a*a+b*b+m)/(a*b);
                  d=(float)(a*a+b*b+m)/(a*b);
                  if(d==v)
                      count++;
              }//for a b
          cout<<"Case"<<" "<<j<<":"<<" "<<count<<endl;
          count=0;
      }//for j
    if(i!=c-1)
        cout<<endl;
  }
  return 0;
}


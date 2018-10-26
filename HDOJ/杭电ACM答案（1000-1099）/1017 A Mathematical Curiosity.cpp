/*
1017 A Mathematical Curiosity
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
/*Input & Sample Input
1�������������������

10 1��ÿ����������е�һ�����ֱ����n,m��
20 3
30 4
0 0��ÿ�����������m=0,n=0����)

Output & Sample Output

Case 1: 2�����������
Case 2: 4
Case 3: 5

(�����������������һ����)*/

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


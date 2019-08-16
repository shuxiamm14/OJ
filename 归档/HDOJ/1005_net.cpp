#include<iostream>
using namespace std;
int main()
{
    int a,b,n,i,m,t[100];
    t[1]=1;
    t[2]=1;
    while(cin>>a>>b>>n)
    {
             if((a==0)&&(b==0)&&(n==0))
                 break;
             a=a%7;
             b=b%7;
                for(i=3;i<100;i++)
                 {
                      t[i]=(a*t[i-1]+b*t[i-2])%7;
                      if((t[i]==1)&&(t[i-1]==1))
                      {
                        break;
                      }
                 }
                 m=n%(i-2);
                 if(m==0)
                  cout<<t[i-2]<<endl;
                 else
                  cout<<t[m]<<endl;
    }
    return 0;
} 

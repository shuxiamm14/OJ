/*
1028 Ignatius and the Princess III
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

15 MS 364 KB 1096 B 
GUN C++
*/
/*
采用二维数组存储信息
列表示解决的数据
行表示产生的各种对中最小值为行值的数目
难度在于会出现重复计算，要不出现过的格式排除
*/
#include <iostream.h>
#include <math.h>
using namespace std;

const int NMAX=120;

int main()
{
    int n,p,ca,cb,cc,ans,avg,temp,solved[1+NMAX/2][NMAX+1]={0};
    solved[0][1]=1;solved[0][2]=2;solved[0][3]=3;solved[0][4]=5;
    solved[1][2]=1;solved[1][3]=2;solved[1][4]=3;solved[2][4]=1;
    solved[0][0]=4;
    while(cin>>n && n<=NMAX)
    {
        if(n>solved[0][0])
        {
            for(ca=solved[0][0]+1;ca<=n;ca++)
            {
                avg=(int)ca/2;ans=0;
                for(cb=1;cb<=avg;cb++)
                {
                    temp=solved[0][ca-cb];
                    for(cc=1;cc<cb;cc++)
                        temp-=solved[cc][ca-cb];
                    solved[cb][ca]=temp;
                    ans+=temp;
                }
                ans++;//加上自身
                solved[0][ca]=ans;
            }
        }
        cout<<solved[0][n]<<endl;
    }
    return 0;
}


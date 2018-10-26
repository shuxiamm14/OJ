/*
1009b FatMouse' Trade
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
//每次的a可以不同
//利益公式: （得到－付出）/付出
//未被AC，但思想相同，可能在边际上错误或精度错误
#include <iostream.h>
using namespace std;

#define MAX 1000

int main()
{
    int m,n,ca,cb,j[MAX]={0},f[MAX]={0},rank[MAX]={0},mark[MAX]={0},max;
    double get,profit[MAX]={0};
    cout.setf(ios::fixed);
    cout.precision(3);
    while(cin>>m>>n && (m>0 && n>0))
    {
        get=0;max=-1;
        for(ca=0;ca<n;ca++)
        {
            cin>>j[ca]>>f[ca];
            profit[ca]=1.0*j[ca]/f[ca];
            mark[ca]=0;
        }
        //对获得的利益进行排序，降序
        for(ca=0;ca<n;ca++)
        {
            max=-1;
            for(cb=0;cb<n;cb++)
            {
                if(max==-1)
                {
                    if(mark[cb]==0)
                    {   max=cb;}
                    else
                        continue;
                }
                if(mark[cb]==0)
                {
                    if(profit[cb]>profit[max])
                        max=cb;
                }
                else
                    continue;
            }
            rank[ca]=max;
            mark[max]=1;
        }
        //按利益顺序进行计算所得
        for(ca=0;ca<n;ca++)
        {
            if(m>0)
            {
                if(m>=f[rank[ca]])
                {   get+=j[rank[ca]];m-=f[rank[ca]];}
                else
                {
                    get+=1.0*j[rank[ca]]*m/f[rank[ca]];m=0;
                }
            }
            else
                break;
        }
        cout<<get<<endl;
    }
    return 0;
}


/*
1009 FatMouse' Trade
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
类似背包问题，贪心算法
*/
#include <iostream>

int main()
{
    int m,n,j[1000],f[1000],p,i,x;
    double a[1000],k,s;
    cout.setf(ios::fixed);
    cout.precision(3);
    cin>>m>>n;
    while(m!=-1&&n!=-1)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            cin>>j[i]>>f[i];
            a[i]=(double)j[i]/(double)f[i];
        }
        for(i=0;i<n;i++)
            for(p=i+1;p<n;p++)
                if(a[i]<a[p])//高收益的排列在前部
                {
                    k=a[i];a[i]=a[p];a[p]=k;
                    x=j[i];j[i]=j[p];j[p]=x;
                    x=f[i];f[i]=f[p];f[p]=x;
                }
        for(i=0;i<n;i++)
            if(m>=f[i])
            {
                s=s+j[i];
                m=m-f[i];
            }
            else
            {
                s=s+a[i]*(double)m;
                break;
            }
        cout<<s<<endl;
        cin>>m>>n;
        }
    return 1;
}


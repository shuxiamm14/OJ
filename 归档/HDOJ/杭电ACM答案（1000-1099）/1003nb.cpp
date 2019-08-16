/*
1003nb Max Sum
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream>
using namespace std;

const int NMAX=100000;

int main()
{
    int t,n,ca,cb,i,j,sum,max,now;
    while(cin>>t)
    {
        for(ca=1;ca<=t;ca++)
        {
            cin>>n;
            sum=0;max=-2147483647;
            for(cb=1;cb<=n;cb++)
            {
                cin>>now;
                sum+=now;
                if(sum>=0 && max<0)
                {   i=cb;}
                if(sum>max)
                {   max=sum;j=cb;}
                if(sum<0)
                {   sum=0;}
            }
            cout<<"Case "<<ca<<":\n"<<max<<" "<<i<<" "<<j<<endl;
            if(ca!=t)
                cout<<endl;
        }
    }
    return 0;
}

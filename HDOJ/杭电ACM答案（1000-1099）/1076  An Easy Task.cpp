/*
1076 An Easy Task
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
using namespace std;

const int NMAX=10000;

int main()
{
    int t,y,ca,cb,n;
    while(cin>>t)
    {
        for(ca=0;ca<t;ca++)
        {
            cin>>y>>n;
            if((y%4==0 && y%100!=0) || y%400==0)
            {   cb=2;}
            else
            {
                cb=1;
                y-=y%4;
            }
            for(;cb<=n;cb++)
            {
                y+=4;
                while(!((y%4==0 && y%100!=0) || y%400==0))//(y%100==0 || y%400!=0)
                {   y+=4;}
            }
            cout<<y<<endl;
        }
    }
    return 0;
}


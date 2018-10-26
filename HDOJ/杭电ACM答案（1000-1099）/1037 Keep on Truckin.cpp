/*
1037 Keep on Truckin'
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream>
using namespace std;

const int Max=300;

int main()
{
    int t,high=168;
    int h[3];
    bool flag;

    while(cin>>h[0]>>h[1]>>h[2])
    {
        t=3;
        flag=true;
        while(t--)
            if(h[t]<=high)
            {   cout<<"CRASH "<<h[t]<<endl;flag=false;}
        if(flag)
            cout<<"NO CRASH\n";
    }
    return 0;
}


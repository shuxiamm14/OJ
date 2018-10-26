/*
1008 Elevator
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream>
using namespace std;

#define NMAX 100

int main()
{
    int n,ca,floorth,goal,mins;
    while(cin>>n && n!=0)
    {
        if(n>NMAX)
            continue;
        floorth=0;mins=0;
        for(ca=0;ca<n;ca++)
        {
            cin>>goal;
            if(goal>floorth)
                mins+=6*(goal-floorth);
            else
                if(goal<floorth)
                    mins+=4*(floorth-goal);
            mins+=5;
            floorth=goal;
        }
        cout<<mins<<endl;
    }
    return 0;
}


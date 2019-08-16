/*
1012 u Calculate e
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream.h>
using namespace std;

#define MAX 1000

int main()
{
    int ca,i=1;
    double e=1;
    cout<<"n e"<<endl<<"- -----------"<<endl;
    cout<<"0 1"<<endl<<"1 2"<<endl<<"2 2.5"<<endl;
    cout.setf(ios::fixed);
    cout.precision(9);
    for(ca=1;ca<10;ca++)
    {
        i*=ca;
        e+=1.0/i;
        if(ca>2)
            cout<<ca<<" "<<e<<endl;
    }
    return 0;
}


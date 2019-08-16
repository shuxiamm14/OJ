/*
1064 Financial Management
Time Limit : 200 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
using namespace std;

const int MAX=1000;

int main()
{
    double total,month;
    cout.setf(ios::fixed);
    cout.precision(2);
    while(cin>>total)
    {
        for(int ca=1;ca<12;ca++)
        {
            cin>>month;
            total+=month;
        }
        cout<<'$'<<total/12<<endl;
    }
    return 0;
}


/*
1065 I Think I Need a Houseboat
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
#include <math.h>
using namespace std;

const int Max=1000;
const float Pi=3.1415926;

int main()
{
    int n,ca,z,land;
    float x,y,r,len;
    cin>>n;
    for(ca=1;ca<=n;ca++)
    {
        cin>>x>>y;
        len=sqrt(x*x+y*y);
        r=0;z=0;land=0;
        while(len>r)
        {
            land+=50;
            r=sqrt(2*land/Pi);
            z++;
        }
        cout<<"Property "<<ca<<": This property will begin eroding in year "<<z<<".\n";
    }
    cout<<"END OF OUTPUT.\n";
    return 0;
}


/*
1071 The area
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
#include <math.h>
using namespace std;

#define MAX 10000

int main()
{
    int t,ca,cb;
    double p1x,p1y,p2x,p2y,p3x,p3y,a,b,c,k,d,area,stepx,nowx,nowy1,nowy2;
    cout.setf(ios::fixed);
    cout.precision(2);
    while(cin>>t)
    {
        for(ca=0;ca<t;ca++)
        {
            cin>>p1x>>p1y>>p2x>>p2y>>p3x>>p3y;
            k=(p3y-p2y)/(p3x-p2x);
            d=p3y-k*p3x;
            a=(p2y-p1y)/((p2x-p1x)*(p2x-p1x));
            b=-2*a*p1x;
            c=p1y+a*p1x*p1x;
            area=0;stepx=(p3x-p2x)/MAX;nowx=p2x;
            for(cb=0;cb<MAX;cb++)
            {
                nowx+=stepx;
                nowy1=k*nowx+d;
                nowy2=a*nowx*nowx+b*nowx+c;
                area+=stepx*(nowy2-nowy1);
            }
            cout<<area<<endl;
        }//for ca
    }//while t
    return 0;
}


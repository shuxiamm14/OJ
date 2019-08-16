/*
1060 Leftmost Digit
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
#include <math.h>
using namespace std;

const int NMAX=1000000000;

double Normal(double num,int & n10)
{
    n10=(int)log10(num);
    return num/pow(10,n10);
}

int main()
{
    int t,n,digit,n10,temp;
    double fn,power;
    while(cin>>t)
    {
        for(int ca=0;ca<t;ca++)
        {
            cin>>n;
            fn=Normal((double)n,n10);
            fn=pow(n,fn);
            fn=Normal(fn,temp);
            for(int cb=0;cb<n10;cb++)
            {
                fn=pow(fn,10);
                fn=Normal(fn,temp);
            }

            digit=(int)Normal(fn,n10);
            cout<<digit<<endl;
        }
    }
    return 0;
}


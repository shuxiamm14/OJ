/*
1049 Climbing Worm
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream.h>
using namespace std;


int main()
{
    int n,d,u,ians;
    while(cin>>n>>u>>d && (n!=0))
    {
        ians=0;
        while(n-u>0)
        {
            n=n-u+d;
            ians+=2;
        }
        ians++;
        cout<<ians<<endl;
    }
    return 0;
}


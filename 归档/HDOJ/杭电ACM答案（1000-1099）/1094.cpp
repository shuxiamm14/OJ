/*
1094 A+B for Input-Output Practice (VI)
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream.h>
using namespace std;

#define MAX 1000

int main()
{
    int n,num,ca,ans;
    while(cin>>n)
    {
        ans=0;
        for(ca=0;ca<n;ca++)
        {   cin>>num;ans+=num;}
        cout<<ans<<endl;
    }
    return 0;
}


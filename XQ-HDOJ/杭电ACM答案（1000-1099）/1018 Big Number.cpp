/*
1018 Big Number
Time Limit : 10000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
//输入n,求n!的位数
#include <iostream.h>
#include <math.h>
using namespace std;

#define NMAX 10000000

int main()
{
    int t,n,ca,cb,digit;
    double num;
    if(cin>>t)
    {
        for(ca=0;ca<t;ca++)
        {
            cin>>n;
            digit=1;num=1;
            for(cb=2;cb<=n;cb++)
            {
                num*=cb;
                if(num<10)
                {   continue;}
                if(num<100)
                {   digit+=1;num/=10;continue;}
                if(num<1000)
                {   digit+=2;num/=100;continue;}
                if(num<10000)
                {   digit+=3;num/=1000;continue;}
                if(num<100000)
                {   digit+=4;num/=10000;continue;}
                if(num<1000000)
                {   digit+=5;num/=100000;continue;}
                if(num<10000000)
                {   digit+=6;num/=1000000;continue;}
                if(num<100000000)
                {   digit+=7;num/=10000000;continue;}
            }
            cout<<digit<<endl;
        }
    }
    return 0;
}


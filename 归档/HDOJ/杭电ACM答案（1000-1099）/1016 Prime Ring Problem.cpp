/*
1016 Prime Ring Problem
Time Limit : 2000 ms  Memory Limit : 32768 K  Output Limit : 4096 K

GUN C++
*/
#include <iostream.h>
using namespace std;

#define NMAX 20

int num[20],ring[19]={0},prime[11]={3,5,7,11,13,17,19,23,29,31,37};

int isPrime(int add)
{
    int ca;
    for(ca=0;ca<11;ca++)
        if(prime[ca]==add)
            return 1;
    return 0;
}

int Initi_ring(int step,int n)
{
    int ca,flag;
    if(step>=n)
    {
        flag=isPrime(1+ring[n-1]);
        if(flag==1)
        {
            for(ca=0;ca<n;ca++)
            {
                cout<<ring[ca];
                if(ca!=n-1)
                cout<<" ";
            }
            cout<<endl;
        }
        return flag;
    }
    else
    {
        for(ca=2;ca<=n;ca++)
        {
            if(num[ca]==0)
            {
                flag=isPrime(ca+ring[step-1]);
                if(flag==1)
                {
                    ring[step]=ca;
                    num[ca]=1;
                    Initi_ring(step+1,n);
                    num[ca]=0;
                    ring[step]=0;
                }

            }
        }//for ca
    }
    return 0;
}

int main()
{
    int n,ca,t=0;
    while(cin>>n && (n>0 && n<NMAX))
    {
        cout<<"Case "<<++t<<":"<<endl;
        ring[0]=1;
        num[0]=1;num[1]=1;
        for(ca=2;ca<=n;ca++)
            num[ca]=0;
        Initi_ring(1,n);
        cout<<endl;

    }
    return 0;
}

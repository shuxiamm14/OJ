/*
1032 The 3n + 1 problem
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
//Çî¾Ù
#include <iostream.h>
using namespace std;

const int nMax=1000000;

unsigned short rec[nMax+1]={0};

int main()
{
    int i,j,ca,temp,max,count;
    while(cin>>i>>j)
    {
        cout<<i<<" "<<j<<" ";
        if(i>j)
        {   temp=i;i=j;j=temp;}
        max=0;
        for(ca=i;ca<=j;ca++)
        {
            if(rec[ca]!=0)
            {   count=rec[ca];}
            else
            {
                temp=ca;count=0;
                while(temp!=1)
                {
                    if(temp%2==1)
                    {   temp=temp*3+1;}
                    else
                        temp/=2;
                    count++;
                }
                rec[ca]=count;
            }
            if(count>max)
                max=count;
        }
        max++;
        cout<<max<<endl;
    }
    return 0;
}


/*
1014 Uniform Generator
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
//类似 1222 Wolf and Rabbit
#include <iostream.h>
#include <iomanip.h>
#include <stdio.h>
using namespace std;

const int MODMAX=100000;

int main()
{
    int step,mod,temp,flag;
    char strout[2][15]={"Bad Choice\n","Good Choice\n"};
    int save[2];
    while(cin>>step>>mod)
    {
        temp=0;save[0]=step;save[1]=mod;
        while(temp!=1)
        {
            temp=step%mod;
            if(temp==0)
                break;
            step=mod;
            mod=temp;
        }
        if(temp==1)
        {   flag=1;}
        else
        {   flag=0;}

        //'\t'产生的PE
        //cout<<setw(10)<<save[0]<<setw(10)<<save[1]<<'\t'<<strout[flag]<<endl;
        //这种变态题目没意思的
        cout<<setw(10)<<save[0]<<setw(10)<<save[1]<<"    "<<strout[flag]<<endl;
        //cout<<"123456789012345678901234567890"<<endl;
        //printf("%10d%10d    %s\n",save[0],save[1],strout[flag]);//四个空格
    }
    return 0;
}


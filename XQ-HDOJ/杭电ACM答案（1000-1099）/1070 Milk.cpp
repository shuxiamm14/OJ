/*
1070 Milk
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>

using namespace std;

#define NMAX 100

int main()
{
    int t,n,ca,cb,day,min,price;
    char brand[NMAX][100];
    float value[NMAX]={0};
    int volume[NMAX]={0};
    if(cin>>t)
    {
        for(ca=0;ca<t;ca++)
        {
            for(cin>>n,cb=0;cb<n;cb++)
            {
                cin>>brand[cb]>>price>>volume[cb];
                if(volume[cb]<200)
                {   value[cb]=-1;continue;}
                day=volume[cb]/200;
                if(day>5)
                    day=5;
                value[cb]=price/day*1.0;
            }
            for(cb=0;cb<n;cb++)
                if(value[cb]>=0)
                {   min=cb;break;}
            for(;cb<n;cb++)
                if(value[cb]>=0 && value[cb]<=value[min])
                {
                    if(value[cb]<value[min])
                        min=cb;
                    else//当同样便宜时选择大容量的
                    {
                        if(volume[cb]>volume[min])
                            min=cb;
                    }
                }
            cout<<brand[min]<<endl;
        }
    }
    return 0;
}

/*
1004 Let the Balloon Rise
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
#include <string.h>
using namespace std;

#define NMAX 1000

int main()
{
    int n,ca,cb,kinds,max,times[NMAX]={0};
    char list[NMAX][16],strnow[16];
    while(cin>>n && n!=0)
    {
        kinds=0;
        for(ca=0;ca<n;ca++)
        {
            cin>>strnow;
            if(kinds==0)
            {   strcpy(list[0],strnow);times[0]++;kinds++;continue;}
            for(cb=0;cb<kinds;cb++)
            {
                if(strcmp(strnow,list[cb])==0)
                {   times[cb]++;break;}
            }
            if(cb==kinds)
            {   strcpy(list[kinds],strnow);times[kinds]++;kinds++;}
        }
        max=0;
        for(ca=0;ca<kinds;ca++)
            if(times[ca]>times[max])
                max=ca;
        cout<<list[max]<<endl;
        for(ca=0;ca<kinds;ca++)
            times[ca]=0;
    }
    return 0;
}

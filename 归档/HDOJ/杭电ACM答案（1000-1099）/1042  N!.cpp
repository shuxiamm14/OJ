/*
1042 N!
Time Limit : 5000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
using namespace std;

const int NMAX=10000;

int Cal(int (&ans)[NMAX],int multip)
{
    int ca,temp;
    for(ca=1;ca<=ans[0];ca++)
    {
        ans[ca]*=multip;
    }
    for(ca=1;ca<=ans[0];ca++)
    {
        temp=ans[ca];
        if(temp>9999)
        {
            ans[ca]=temp%10000;
            if(ca+1>ans[0])
            {   ans[0]=ca+1;ans[ca+1]=0;}
            ans[ca+1]+=(int)temp/10000;
        }
    }
    return 0;
}

int main()
{
    int n,ca;
    int ans[NMAX]={0};
    cout.setf(ios::fixed);
    while(cin>>n && (n>=0 && n<=NMAX))
    {
        if(n==0)
        {    cout<<1<<endl;continue;}
        ans[0]=1;ans[1]=1;
        for(ca=2;ca<=n;ca++)
        {
            Cal(ans,ca);
        }
        for(ca=ans[0];ca>=1;ca--)
        {
            if(ca==ans[0])
            {
                cout<<ans[ans[0]];
            }
            else
            {
                if(ans[ca]>=1000)
                {   cout<<ans[ca];}
                else
                {
                    if(ans[ca]>=100)
                    {   cout<<"0"<<ans[ca];}
                    else
                    {
                        if(ans[ca]>=10)
                        {   cout<<"00"<<ans[ca];}
                        else
                        {   cout<<"000"<<ans[ca];}
                    }
                }
            }//if
        }//for
        cout<<endl;
    }
    return 0;
}


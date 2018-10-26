#include<iostream>
#define Min -999999
using namespace std;
int main()
{
    int data[100000],start,end;
    int m;
    int step=1;
    cin>>m;
    while(m--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n;i++)
            cin>>data[i];
        int max = Min;
        int k=1;
        int sum = 0;
        for (int i=1; i<=n; i++)
        {
            sum = sum + data[i];
            if (sum > max)
            {
                max = sum;
                start=k;
                end=i;
            }
            if(sum<0)
            {
                sum=0;
                k=i+1;
            }
        }
        if(step!=1)
            cout<<endl;
        cout<<"Case "<<step<<":"<<endl;
        cout<<max<<" "<<start<<" "<<end<<endl;
        step++;
    }
    return 0;
}

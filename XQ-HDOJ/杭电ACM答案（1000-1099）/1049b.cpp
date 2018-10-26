/*
1049b Climbing Worm
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream.h>
//#include <fstream.h>
using namespace std;

//ofstream fout( "results.txt", ios::app );

int method1(int n,int d,int u)
{
    int ians;
    ians=0;
    while(n-u>0)
    {
        n=n-u+d;
        ians+=2;
    }
    ians++;
    cout<<ians<<endl;
    //fout<<"1049:"<<ians<<endl;
    return 0;
}


int method2(int n,int d,int u)
{
    int ians;
    ians=(n-u)/(u-d);
    if((n-u)%(u-d)!=0)
    {   ians++;ians*=2;}
    else
    {   ians*=2;}
    ians++;
    cout<<ians<<endl;
    //fout<<"1049b:"<<ians<<endl;
    return 0;
}

int main()
{
    int n,d,u,ians;

    while(cin>>n>>u>>d && (n!=0))
    {
        //method1(n,d,u);
        method2(n,d,u);
    }
    //fout.close();
    return 0;
}


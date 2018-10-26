/*
1038 Biker's Trip Odometer
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream>
using namespace std;
const float Pi=3.1415927;

int main()
{
    int n,i;
    int r;
    float d,t,dis,mph;
    
    n=1;
    cout.setf(ios::fixed);
    cout.precision(2);
    while(cin>>d>>r>>t && r!=0)
    {
        dis=Pi*d*r/63360;//=5280*12
        mph=3600*dis/t;
        cout<<"Trip #"<<n<<": "<<dis<<" "<<mph<<endl;
        n++;
    }
    return 0;
}


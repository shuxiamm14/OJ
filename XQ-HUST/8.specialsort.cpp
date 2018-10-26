#include <iostream>
#include <vector>
using namespace std;
int main()
    {
  int n;
    while(cin>>n)
        {
        vector<int> a;
        int b;
        int max;
        for(int i=0;i<n;i++)
            {
            cin>>b;
            a.push_back(b);
        }
          if(n==1)
            cout<<a[0]<<endl<<-1;
        else{
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    max=a[j];
                    a[j]=a[j+1];
                    a[j+1]=max;
                }
            }
      cout<<a[n-1]<<endl;
        for(int i=0;i<n-2;i++)
            {
             
            cout<<a[i]<<' ';
        }
             cout<<a[n-2];
        }
        cout<<endl;
    }
    return 0;
}
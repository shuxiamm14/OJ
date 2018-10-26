/*
1087 Super Jumping! Jumping! Jumping!
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
/*
F[i] = max(F[p]) + C[i] (0 <= p < i <= n �� C[p] < C[i])
F[0] = C[0]
���������һ�ε����������ε�����ֵ������ȫ������
*/
#include <iostream>
using namespace std;
const int nMax=1000;

int main()
{
    int temp,n,i,j,max[nMax],ans;
    int value[nMax];
    
    while(cin>>n && n!=0)
    {
        for(i=0;i<n;i++)
            cin>>value[i];

        ans=max[0]=value[0];
        for(i=1;i<n;i++)
        {
            temp=0;
            for(j=i-1;j>=0;j--)
                if(max[j]>temp && value[i]>value[j])
                    temp=max[j];
            max[i]=temp+value[i];
            if(max[i]>ans)
                ans=max[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}


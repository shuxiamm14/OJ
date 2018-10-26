/*
1061 Rightmost Digit
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
//��֤��ʱ�����ظ����ڸ���n��ֵȷ�����һλ���ظ��г��ֵ�λ��
#include <iostream.h>
using namespace std;

const int NMAX=1000000000;

int main()
{
    int t,n;
    int lastdigit,last[10]={0},now;
    while(cin>>t)
    {
        for(int ca=0;ca<t;ca++)
        {
            cin>>n;
            lastdigit=n%10;
            last[0]=lastdigit;
            now=1;last[1]=lastdigit*lastdigit%10;
            while(last[0]!=last[now])
            {
                now++;
                last[now]=last[now-1]*lastdigit%10;
            }
            lastdigit=last[(n-1)%now];
            cout<<lastdigit<<endl;
        }
    }
    return 0;
}


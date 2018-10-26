/*
1097 A hard puzzle
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
//œ‡Õ¨”⁄ 1061 Rightmost Digit
#include <iostream.h>
using namespace std;

const int MAX=20;

int main()
{
    long a,b;
    int lastdigit,last[MAX]={0},now;
    while(cin>>a>>b)
    {
        if(a==1 || b==0)
        {   cout<<1<<endl;continue;}
        lastdigit=a%10;
        last[0]=lastdigit;
        now=1;last[1]=lastdigit*lastdigit%10;
        while(last[0]!=last[now])
        {
            now++;
            last[now]=last[now-1]*lastdigit%10;
        }
        lastdigit=last[(b-1)%now];
        cout<<lastdigit<<endl;
    }
    return 0;
}


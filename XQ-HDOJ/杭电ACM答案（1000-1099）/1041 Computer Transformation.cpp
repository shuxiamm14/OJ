/*
1041 Computer Transformation
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

343 MS 352 KB 1549 B 
GUN C++
*/
/*
将序列分成对半看
列出由1开始和由0开始的序列，设f(n),g(n)为两个序列的零对的对数
flag(n):当n为奇数＝0，n为偶数为1;此函数为左右序列合并时中间的一对数配对情况
f(n)中间一对不会出现11；g(n)中间一对不会出现00；所以可列出递推式：
f(n)=g(n-1)+flag(n)+f(n-1);
g(n)=f(n-1)+0+g(n-1);   g(n-1)=f(n-2)+0+g(n-2);
代入得：f(n)=f(n-2)+g(n-2)+flag(n)+f(n-1);
            =2f(n-2)+2g(n-2)+flag(n)+flag(n-1);
            =2f(n-1)+flag(n)-flag(n-1);
*/

#include <iostream.h>
using namespace std;

const long NMAX=1000;
long flag[2]={1,0};
int bignum[NMAX]={0};

long long solve(long step)//递归式没错
{
    if(step==2)
    {   return 1;}
    else
    {
        return 2*solve(step-1)+flag[step%2]-flag[(step-1)%2];
    }
}

int sum(int mode)
{
    int ca,len,temp=0;
    len=bignum[0];
    for(ca=1;ca<=len;ca++)
    {
        bignum[ca]*=2;
        bignum[ca]+=mode;
        temp=bignum[ca];
        if(temp>=1000)
        {
            bignum[ca]%=1000;
            if(ca==len)
            {
                bignum[ca+1]=(temp-bignum[ca])/1000;
                bignum[0]++;
            }
            else
            {   mode=(temp-bignum[ca])/1000;}
        }
        else
        {   mode=0;}
    }
    return 1;
}

int solve2(long step)//注意大数，模拟相乘
{
    int ca,temp;
    if(step<=2)
    {   cout<<1<<endl;return 1;}
    bignum[0]=bignum[1]=1;
    for(ca=3;ca<=step;ca++)
    {
        if(ca%2==0)
        {   //pair=pair*2+1;
            sum(1);
        }
        else
        {   //pair=pair*2-1;
            sum(-1);
        }
    }
    for(ca=bignum[0];ca>0;ca--)
    {
        if(ca!=bignum[0])
        {
                if(bignum[ca]<100)
                {
                    cout<<0;
                    if(bignum[ca]<10)
                    {   cout<<0;}
                }
        }
        cout<<bignum[ca];
    }
    cout<<endl;
    return 1;
}

int main()
{
    long n,ca;
    double pair;
    while(cin>>n && n<=NMAX)
    {
        pair=0;
        if(n==1)
        {
            cout<<0<<endl;
            //pair=0;
        }
        else
        {
            //pair=solve(n);
            
            //pair=1;
            //for(ca=3;ca<=n;ca++)
            //{   pair=2*pair+flag[ca%2]-flag[(ca-1)%2];}//递归简化式
            
            solve2(n);
        }
        //cout<<pair<<endl;
    }
    return 0;
}


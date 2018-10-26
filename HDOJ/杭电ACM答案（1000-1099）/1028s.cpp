/*
1028s Ignatius and the Princess III
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

0 MS 352 KB 1003 B 
GUN C++
*/
//母函数及其应用(Generation function)
//G(x)=(1+x+x^2+....)(1+x^2+x^4+....)(1+x^3+x^6+....)(1+x^4+x^8+....)....(1+x^n)

#include <iostream.h>
using namespace std;

const int lmax=1000;

int c1[lmax+1],c2[lmax+1];//c1保存计算后的答案，c2保存正在进行的计算答案
//使用下标来表示x的指数，数值来表示系数
int main()
{	
    int n,i,j,k;
	while (cin>>n)
    {
        for(i=0;i<=n;i++)
        {   c1[i]=1;    c2[i]=0;}
        for(i=2;i<=n;i++)//每次递增的指数i
        {	
            for(j=0;j<=n;j++)//c1(上次计算的答案)的各个x指数的系数，j表示x的指数
                for(k=0;k+j<=n;k+=i)//k表示进行相乘的数的各个指数，递增指数为i,因为要重复使用
                {   c2[j+k]+=c1[j];}//(a1*x^j)*(x^k)=a1*x^(j+k)
				
            for(j=0;j<=n;j++)
            {   c1[j]=c2[j];    c2[j]=0;}//将计算完成的答案作为下次计算的基础
		}
        cout<<c1[n]<<endl;
	}
	return 0;
}

/*
1028s Ignatius and the Princess III
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

0 MS 352 KB 1003 B 
GUN C++
*/
//ĸ��������Ӧ��(Generation function)
//G(x)=(1+x+x^2+....)(1+x^2+x^4+....)(1+x^3+x^6+....)(1+x^4+x^8+....)....(1+x^n)

#include <iostream.h>
using namespace std;

const int lmax=1000;

int c1[lmax+1],c2[lmax+1];//c1��������Ĵ𰸣�c2�������ڽ��еļ����
//ʹ���±�����ʾx��ָ������ֵ����ʾϵ��
int main()
{	
    int n,i,j,k;
	while (cin>>n)
    {
        for(i=0;i<=n;i++)
        {   c1[i]=1;    c2[i]=0;}
        for(i=2;i<=n;i++)//ÿ�ε�����ָ��i
        {	
            for(j=0;j<=n;j++)//c1(�ϴμ���Ĵ�)�ĸ���xָ����ϵ����j��ʾx��ָ��
                for(k=0;k+j<=n;k+=i)//k��ʾ������˵����ĸ���ָ��������ָ��Ϊi,��ΪҪ�ظ�ʹ��
                {   c2[j+k]+=c1[j];}//(a1*x^j)*(x^k)=a1*x^(j+k)
				
            for(j=0;j<=n;j++)
            {   c1[j]=c2[j];    c2[j]=0;}//��������ɵĴ���Ϊ�´μ���Ļ���
		}
        cout<<c1[n]<<endl;
	}
	return 0;
}

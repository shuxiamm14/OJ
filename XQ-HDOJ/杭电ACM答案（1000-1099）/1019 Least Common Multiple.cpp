/*
1019 Least Common Multiple
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream.h>
using namespace std;


long  LCM(long  num1,long  num2)
{
    long int a,b,temp;
    if(num1>0 && num2>0)
    {
        if(num1<num2)/*交换两个数，使大数放在num1上*/
        {
            temp=num1;
            num1=num2;
            num2=temp;
        }
        a=num1;b=num2;
        while(b!=0)/*利用辗除法，直到b为0为止*/
        {
            temp=a%b;
            a=b;
            b=temp;
        }
        num1/=a;
        return num1*num2;
        /*应该很大的数超过了它的范围
        return num1*num2/a ;
        应该是这个问题!
        num1 /= a ;
        return num1 * num 2 ;
        */
    }
    else
    {   return 0;}

}

int main()
{
    int t,n,ca,cb;
    long num1,num2;
    if(cin>>t)
    {
        for(ca=0;ca<t;ca++)
        {
            cin>>n;
            cin>>num1;
            for(cb=1;cb<n;cb++)
            {
                cin>>num2;
                num1=LCM(num1,num2);
            }//n
            cout<<num1<<endl;
        }//t
    }
    return 0;
}


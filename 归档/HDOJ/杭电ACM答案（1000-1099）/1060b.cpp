/*
1060b Leftmost Digit
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

0 MS 364 KB 425 B 
GUN C++
*/
#include <iostream.h>
#include <math.h>
#define e 2.718281828459045376

int main()
{
  long test ;
  long double bit ;
  long long n ;
  cin >> test ;

    while( test --)
    {
        cin>>n;
        long double temp;
        long double i;
        temp=n*log(n);
        i=floor(temp/log(10));
        temp=temp-i*log(10);
        bit=pow(e,temp);
        cout<<int(bit)<<endl;
    }
   return 0 ;
}

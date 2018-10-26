/*
1058 Humble Numbers
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int Max=5842;
int h[Max+1];

int main()
{
    int i,n;
    double temp1,temp2;
    int l2=0,l3=0,l5=0,l7=0;

    h[0]=1;
    for(i=1;i<5842;i++)
    {
        temp1=2*h[l2]>3*h[l3] ? 3*h[l3]:2*h[l2];
        temp2=5*h[l5]>7*h[l7] ? 7*h[l7]:5*h[l5];
        h[i]=temp1>temp2 ? temp2:temp1;
        if (h[i]==2*h[l2]) l2++;
        if (h[i]==3*h[l3]) l3++;
        if (h[i]==5*h[l5]) l5++;
        if (h[i]==7*h[l7]) l7++;
    }

    while(scanf("%d",&n)==1 && n!=0)
    {
        int fir,sec;
        char suf[10];

        fir = n % 10;
 		sec = (n / 10) % 10;

 		strcpy(suf, "th");
 		if (sec != 1)
 		{
 			if (fir == 1 )
 				strcpy(suf, "st");
 			else if (fir == 2)
 				strcpy(suf, "nd");
 			else if (fir == 3)
 				strcpy(suf, "rd");
 		}
 		printf("The %d%s humble number is %d.\n",n,suf,h[n-1]);
        //cout << "The " << n << suf << " humble number is " << h[n-1] << "." << endl;
    }
    return 0;
}


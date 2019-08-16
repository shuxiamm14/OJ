/*
1021 Fibonacci Again
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K
GUN C
*/
#include <stdio.h>

#define NMAX 1000000

int main()
{
    long n;
    while(scanf("%ld",&n) ==1)
	   if (n%8==2 || n%8==6)
		   printf("yes\n");
	   else
		   printf("no\n");
	return 0;
}


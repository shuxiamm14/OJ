#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <cstring>
#include <iostream>
void fun(char ch)
{
    std::bitset<8> bit;
    bit = ch;
    if (bit.count() % 2 == 0)
        bit.set(7);
    std::cout << bit << '\n';
}
int main()
{
    char s[1000];
    while (scanf("%s", s))
    {
        int len = (int)strlen(s);
        for (int i = 0; i < len; ++i)
            fun(s[i]);
    }
    return 0;
}

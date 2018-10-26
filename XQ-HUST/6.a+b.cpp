#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
struct bigInt
{
    int num[10002];
    int size;
    void init()
    {
        size = 0;
        for (int i = 0; i < 1002; ++i)
        {
            num[i] = 0;
        }
    }
    void set(char str[])
    {
        init();
        int len = strlen(str);
        for (int i = len - 1, j = 0, c = 1, temp = 0; i >= 0; --i)
        {
            temp = temp + (str[i] - '0') * c;
            j++;
            c *= 10;
            if (j == 4 || i == 0)
            {

                num[size++] = temp;
                temp = 0;
                j = 0;
                c = 1;
            }
        }
    }
    bigInt operator+(const bigInt &x) const
    {
        bigInt ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < x.size || i < size; ++i)
        {
            int temp = x.num[i] + num[i] + carry;
            carry = temp / 10000;
            temp %= 10000;
            ret.num[ret.size++] = temp;
        }
        if (carry != 0)
        {
            ret.num[ret.size++] = carry;
        }
        return ret;
    }
    void outPut()
    {
        for (int i = size - 1; i >= 0; --i)
        {
            if (i != size - 1)
                printf("%04d", num[i]);
            else
                printf("%d", num[i]);
        }
        printf("\n");
    }
};
int main()
{
    char str1[1002], str2[1002];
    bigInt a, b, c;
    while (scanf("%s%s", str1, str2) != EOF)
    {
        a.set(str1);
        b.set(str2);
        c = a + b;
        c.outPut();
    }

    return 0;
}

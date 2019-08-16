/*
1039 Easier Done Than Said?
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int Max=21;
char in[Max];

inline bool isvowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    else
        return false;
}

int main()
{
    int t,n,i,len;
    int flag1,flag2,vowels;
    bool ac;

    while(scanf("%s",in)==1)
    {
        len=strlen(in);
        if(len==3 && in[0]=='e' && in[1]=='n' && in[2]=='d')
            break;
        ac=true;
        vowels=flag1=flag2=0;
        if(isvowel(in[0]))
        {   vowels++;flag1++;}
        else
            flag2++;
        for(i=1;i<len;i++)
        {
            if(isvowel(in[i]))
            {   vowels++;flag1++;flag2=0;}
            else
            {   flag2++;flag1=0;}
            if(flag1==3 || flag2==3)
            {   ac=false;break;}
            if(in[i]==in[i-1])
                if(in[i]!='e' && in[i]!='o')
                {   ac=false;break;}
        }
        if(vowels==0)
            ac=false;
        if(ac)
            printf("<%s> is acceptable.\n",in);
        else
            printf("<%s> is not acceptable.\n",in);
    }
    return 0;
}


/*
1048 The Hardest Problem Ever
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K
GUN C
*/

#include <stdio.h>
#include <string.h>

#define CMAX 201
#define DMAX 100

int main()
{
    char plain[26]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
    char strin[CMAX],text[DMAX][CMAX];
    char start[6]="START",end[4]="END",endinput[11]="ENDOFINPUT";
    int total=-1,len,ca;
    gets(strin);strupr(strin);
    while(strcmp(strin,endinput)!=0)
    {
        if(strcmp(strin,start)==0)
        {
            gets(strin);strupr(strin);
            len=strlen(strin);
            total++;

        }
        else
        {
            if(strcmp(strin,end)==0)
            {   gets(strin);strupr(strin);}
            else
            {
                for(ca=0;ca<len;ca++)
                {
                    if(strin[ca]>=65 && strin[ca]<=90)
                        text[total][ca]=plain[strin[ca]-65];
                    else
                        text[total][ca]=strin[ca];
                }
                text[total][ca]='\0';
                gets(strin);strupr(strin);
            }
        }
    }
    for(ca=0;ca<=total;ca++)
        printf("%s\n",text[ca]);
    return 0;
}


//最后字符串长度
#include<stdio.h>
#include <string.h>
int main()
{
    char a[10000];
    int count,i,n;
    count=0;
    gets(a);
    n=(int)strlen(a)-1;
    for(i=n;i>=0;i--)
    {
        if(a[i]!=' ')
            count++;
        if(count>0)
            if(a[i]==' ')
                break;
    }
    printf("%d\n",count);
    return 0;
}

/*
1062 Text Reverse
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream.h>
#include <string.h>
using namespace std;

#define MAX 1000

int main()
{
    int n,ca,cb,cc,i,len;
    char str[MAX]={0};
    while(cin>>n)
    {
        cin.ignore();
        for(ca=0;ca<n;ca++)
        {

            cin.getline(str,MAX);
            len=strlen(str);i=-1;
            for(cb=0;cb<=len;cb++)
            {
                if(str[cb]==' ' || str[cb]=='\0')
                {
                    for(cc=cb-1;cc>i;cc--)
                    {   cout<<str[cc];}
                    if(str[cb]!='\0')
                        cout<<' ';
                    i=cb;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}


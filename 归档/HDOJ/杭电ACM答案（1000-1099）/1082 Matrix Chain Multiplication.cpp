/*
1082 Matrix Chain Multiplication
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
//Ä£ÄâÕ»²Ù×÷
#include <iostream>
//#include <fstream>
//ifstream fin("data.txt");
using namespace std;

const int Max=26;
const int cMax=100;
typedef struct
{
    int x;
    int y;
}MNode;

int main()
{
    int t,ca,ans;
    char mname;
    MNode matrix[Max];
    char chain[cMax],*pch;
    char optr[cMax],*ptr;
    MNode opnd[cMax],*pnd;
    cin>>t;
    for(ca=0;ca<t;ca++)
    {   cin>>mname;cin>>matrix[mname-'A'].x>>matrix[mname-'A'].y;}
    cin.ignore(1);
    while(cin.getline(chain,cMax))
    {
        pch=chain;ptr=optr;pnd=opnd;ans=0;
        while(*pch!='\0')
        {
            switch(*pch)
            {
            case '(':
                *ptr='(';ptr++;
                break;
            case ')':
                if(*(ptr-1)=='(')
                {
                    if((pnd-2)->y==(pnd-1)->x)
                    {
                        pnd--;
                        ans+=(pnd->x)*(pnd->y)*( (pnd-1)->x );
                        (pnd-1)->y=pnd->y;
                    }
                    else
                    {   ans=-1;goto out;}
                    ptr--;
                }
                else
                {   ans=-1;goto out;}
                break;
            default :
                if(*pch>='A' && *pch<='Z')
                {   *pnd=matrix[*pch-'A'];pnd++;}
            }
            pch++;
        }//while
        
        
out:    if(ans>=0)
            cout<<ans<<endl;
        else
            cout<<"error\n";
    }
    //fin.close();
    return 0;
}


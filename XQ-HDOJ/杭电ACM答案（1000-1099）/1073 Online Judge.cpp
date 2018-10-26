/*
1073 Online Judge
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream>
#include <string>
//#include <fstream>
//ifstream fin("data.txt");
using namespace std;

const int Max=5000;

char* changeString(char *pnow,char *temp)
{
    int ca=0;
    while(temp[ca]!='\0')
    {   *pnow=temp[ca];ca++;pnow++;}
    *pnow='\n';pnow++;
    return pnow;
}

bool isPAC(char *user,char *ans)
{
    while(*user!='\0')
    {
        if(*user==*ans)
        {   user++;ans++;}
        else
        {
            while(*user==' ' || *user=='\n' || *user=='\t')
            {   user++;}
            while(*ans==' ' || *ans=='\n' || *ans=='\t')
            {   ans++;}
            if(*user==*ans)
            {   user++;ans++;}
            else
                return false;
        }//if
    }//while
    return true;
}

int main()
{
    int t,n,ca;
    char ans[Max],user[Max],temp[Max];
    char *pnow;
    int flag;
    bool begin;
    cin>>t;
    cin.ignore(1);
    for(ca=0;ca<t;ca++)
    {
        begin=false;
        pnow=ans;
        for(;;)
        {
            cin.getline(temp,Max);
            if(strcmp(temp,"END")==0)
            {   begin=false;break;}
            if(strcmp(temp,"START")!=0)
            {
                if(begin)
                    pnow=changeString(pnow,temp);
            }
            else
                begin=true;
        }
        *pnow='\0';
        
        pnow=user;
        for(;;)
        {
            cin.getline(temp,Max);
            if(strcmp(temp,"END")==0)
            {   begin=false;break;}
            if(strcmp(temp,"START")!=0)
            {
                if(begin)
                    pnow=changeString(pnow,temp);
            }//for
            else
                begin=true;
        }//for n
        *pnow='\0';
        
        if(strcmp(user,ans)==0)
            flag=0;
        else
        {
            if(isPAC(user,ans))
                flag=1;
            else
                flag=2;
        }
        
        if(flag==0)
            cout<<"Accepted\n";
        else
            if(flag==1)
                cout<<"Presentation Error\n";
            else
                cout<<"Wrong Answer\n";
    }
    //fin.close();
    return 0;
}


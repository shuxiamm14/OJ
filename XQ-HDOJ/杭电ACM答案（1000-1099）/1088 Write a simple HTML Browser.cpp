/*
1088 Write a simple HTML Browser
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
   string result;
   int length,i,j;
   char str[100];

    length=80;
    while(cin>>str)
    {
       if(str[0]=='<'&&str[1]=='b')
       {
           if(result!="")
           for(j=0;j<result.length()-1;j++)
                   cout<<result[j];

           result="";
           cout<<endl;
           length=80;
       }
       else if(str[0]=='<'&&str[1]=='h')
       {
           if(result!="")
           {
               for(j=0;j<result.length()-1;j++)
                   cout<<result[j];
               cout<<endl;

               result="";
               length=80;
               for(i=0;i<80;i++)
                   cout<<'-';
               cout<<endl;
           }
           else
           {
               for(i=0;i<80;i++)
                   cout<<'-';
               cout<<endl;
           }
       }
       else
       {
            if(strlen(str)>length)
            {
                for(j=0;j<result.length()-1;j++)
                    cout<<result[j];
                cout<<endl;

                result="";
                length=80;
            }

            result.insert(result.length(),str);
            length=length-strlen(str);
            if(length==0)
            {
                for(j=0;j<result.length()-1;j++)
                   cout<<result[j];
                cout<<endl;

                result="";
                length=80;
            }
            else
            {
                result.insert(result.length()," ");
                length=length-1;
            }
        }
    }
    for(j=0;j<result.length()-1;j++)
        cout<<result[j];
    cout<<endl;

   return 0;
}


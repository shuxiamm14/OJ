/*
1022 Train Problem I
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream>
#include <string>
using namespace std;

const int Max=100;

int Locate(char array[],char num,int low,int high)
{
    for(; array[low]!=num && low<=high ;low++);
    if(array[low]!=num)
        return -1;
    else
        return low;
}

int main()
{
    int loc,n,i,j,step;
    char order1[Max],order2[Max],station[10];
    int run[Max];
    int top,po1;
    bool flag;

    while(cin>>n)
    {
        cin>>order1;
        cin>>order2;

        memset(station,0,sizeof(station));
        top=po1=step=0;
        flag=true;
        for(i=0;i<n;i++)
        {
            loc=Locate(station,order2[i],0,top); //在车站的位置
            if(loc<0)
            {
                loc=Locate(order1,order2[i],po1,n);  //在进入队列的位置
                if(loc<0)
                {   flag=false;break;}
                else
                {
                    for(; po1<loc && top<=9 ; po1++,top++,step++)
                    {
                        station[top]=order1[po1];
                        run[step]=1;
                    }
                    po1=loc+1; // 出栈本元素
                    run[step++]=1;
                    run[step++]=0;
                }//if
            }
            else
            {
                if(loc==top-1)
                {
                    run[step++]=0;
                    top--;station[top]=0;
                }
                else
                {   flag=false;break;}
            }
        }//for
        
        if(flag)
        {
            cout<<"Yes.\n";
            for(i=0;i<step;i++)
                if(run[i])
                    cout<<"in\n";
                else
                    cout<<"out\n";
        }
        else
            cout<<"No.\n";
        cout<<"FINISH\n";
    }
    return 0;
}


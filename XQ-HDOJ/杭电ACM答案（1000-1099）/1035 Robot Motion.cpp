/*
1035 Robot Motion
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char map[11][11];
int v[11][11];
int c,r,s;

inline bool isOut(int x,int y)
{
    if(x<0 || x>=r || y<0 || y>=c)
        return true;
    else
        return false;
}

int main()
{
    int n,i,step,x,y;
    char temp;

    while(cin>>r>>c && r!=0)
    {
        cin>>s;
        for(i=0;i<r;i++)
            cin>>map[i];
        memset(v,0,sizeof(v));
        step=1;
        x=0;y=s-1;
        while(! isOut(x,y) && v[x][y]==0)
        {
            v[x][y]=step;
            switch(map[x][y])
            {
            case 'N':
                x--;break;
            case 'S':
                x++;break;
            case 'W':
                y--;break;
            case 'E':
                y++;break;
            }
            step++;
        }
        if( isOut(x,y) )
            printf("%d step(s) to exit\n",step-1);
        else
            printf("%d step(s) before a loop of %d step(s)\n",v[x][y]-1,step-v[x][y]);
    }
    return 0;
}


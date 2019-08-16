/*
1010 Tempter of the Bone
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 1024 K

GUN C++
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int nmMax=7;
const int tMax=50;

char maze[nmMax][nmMax];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int t,n,m;
int si,sj,ei,ej;


bool DFS(int pi,int pj,int now)
{
    int i,step;
    
    if(pi<0 || pj<0 || pi>=n || pj>=m)
        return false;
        
    if(pi==ei && pj==ej && now==t)
        return true;
        
    step=t-now-abs(ei-pi)-abs(ej-pj);
    if(step<0 || step%2==1)
        return false;
        
    for(i=0;i<4;i++)
    {
        if( maze[ pi+dir[i][0] ][ pj+dir[i][1] ] != 'X')
        {
            maze[ pi+dir[i][0] ][ pj+dir[i][1] ] = 'X';

            if( DFS(pi+dir[i][0], pj+dir[i][1], now+1) )
                return true;
                
            maze[ pi+dir[i][0] ][ pj+dir[i][1] ] = '.';
        }
    }

    return false;
}

int main()
{
    int i,j;
    int flag;
    
    while(cin>>n>>m>>t && (n!=0 && m!=0 && t!=0))
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            cin>>maze[i];
            if(flag<2)
                for(j=0;j<strlen(maze[i]);j++)
                {
                    if(maze[i][j]=='S')
                    {   si=i;    sj=j;  flag++;}
                    if(maze[i][j]=='D')
                    {   ei=i;    ej=j;  flag++;}
                }
        }

        maze[si][sj] = 'X';
        if( DFS(si,sj,0) ) //起始时为0
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}


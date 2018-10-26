/*
1086 You can Solve a Geometry Problem too
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K

GUN C++
*/
#include <iostream>
using namespace std;

const int nMax=100;

struct Point
{
     double x, y;
};

struct Seg
{
     Point begin;
     Point end;
     Seg()
     {};
     Seg(Point& b, Point& e):begin(b), end(e)
     {};
};

double Min(double a,double b)
{
    return a>b ? b : a;
}

double Max(double a,double b)
{
    return a>b ? a : b;
}

double Direction(Point& a,Point& b,Point& c)
{
     return (a.x-c.x)*(b.y-c.y) - (b.x-c.x)*(a.y-c.y);
}

bool Cross(Seg& u,Seg& v)
{
     return (Direction(v.begin, u.end,u.begin)*Direction(u.end, v.end, u.begin)>=0)&&
         (Direction(u.begin,v.end,v.begin)*Direction(v.end,u.end,v.begin)>=0)&&
         (Max(u.begin.x, u.end.x) >= Min(v.begin.x, v.end.x)) &&
         (Max(v.begin.x, v.end.x) >= Min(u.begin.x, u.end.x)) &&
         (Max(u.begin.y, u.end.y) >= Min(v.begin.y, v.end.y)) &&
         (Max(v.begin.y, v.end.y) >= Min(u.begin.y, u.end.y));
}


int main()
{
    int ans,n,i,j;
    Seg in[nMax];
    
    while(cin>>n && n!=0)
    {
        for(i=0 ; i<n ; i++)
            cin>>in[i].begin.x>>in[i].begin.y>>in[i].end.x>>in[i].end.y;
            
        ans=0;
        for(i = 0; i < n; i++)
              for(j = i + 1; j < n; j++)
                   if( Cross(in[i], in[j]) )
                        ans++;
         cout << ans << endl;
    }
    return 0;
}

